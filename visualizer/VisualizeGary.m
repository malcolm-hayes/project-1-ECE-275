function VisualizeGary(boardSize, filename, markersize)
% Check that the boardsize is 
if (mod(boardSize, 2) == 0)
    fprintf("ERROR: Boardsize must be odd. Program won't work properly\n");
    return
end

% Call function to parse the output files
fprintf("Reading board data from file ...\n")
[board, gary] = read_output_file(boardSize, filename);

fprintf("Beginning animation ...\n")
[~, ~, frame] = size(board);
fig = figure;
for i = 1:frame
    % Grab the frame for this loop
    B = board(:, :, i);
    % Binarize 
    B = imbinarize(B);
    % Plot the board for this frame
    imagesc(B);
    title(sprintf("Step %d of %d", i-1, frame-1))
    % Get the Gary for this frame
    g = gary{i};
    % Plot gary and his orientation
    hold on
    plot(g.location(2), g.location(1), ...
        GaryOrientation(g.orient), 'MarkerFaceColor', 'white', ...
        'MarkerSize', markersize)
    hold off;
    
    % Get a frame to make an animation
    im{i} = frame2im(getframe(fig));
end

% Make the animation
fprintf("Making animation now... \n")
gifFilename = "output.gif";
for i = 1:frame
    [A,map] = rgb2ind(im{i},256);
    if i == 1
        imwrite(A, map, gifFilename,'gif', ...
            'LoopCount',Inf,'DelayTime', 0.1);
    else
        imwrite(A, map, gifFilename,'gif', ...
            'WriteMode','append','DelayTime', 0.1);
    end
end

end