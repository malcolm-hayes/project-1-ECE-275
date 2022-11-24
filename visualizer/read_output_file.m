function [board, gary] = read_output_file(boardSize, filename)

board = [];
gary = {};
frame = 0;

fid = fopen(filename);
while (~feof(fid))
    % Incriment the frame
    frame = frame + 1;
    % Get the line from the file
    line = fgetl(fid);
    % Get gary's location
    Gary.location = sscanf(line, "[Gary Location] {%d, %d}")' + 1;
    % Get Gary's orientation
    l = strtrim(extractBetween(line, "[Gary Orientation]" ,"[Row 0]"));
    Gary.orient = l{1};
    % Get the color of each cell in each row
    for i = 1:boardSize - 1
        % Get Row i's colors
        l = extractBetween(line, sprintf("[Row %d] ", i-1), ...
            sprintf(" [Row %d]", i));
        colors = sscanf(l{1}, "%d", [1, boardSize]);
        % Place the colors in the board multi-array
        board(i, :, frame) = colors;
    end
    % Get the last row's colors
    l = extractAfter(line, sprintf("[Row %d] ", boardSize - 1));
    colors = sscanf(l, "%d", [1, boardSize]);
    board(boardSize, :, frame) = colors;
    gary{frame} = Gary;
    
end

end