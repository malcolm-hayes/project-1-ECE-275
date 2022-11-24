function s = GaryOrientation(g)
if strcmp(g, 'up')
    s = "x";
elseif strcmp(g, 'down')
    s = "o";
elseif strcmp(g, 'right')
    s = ">";
else 
    s = "<";
end
end