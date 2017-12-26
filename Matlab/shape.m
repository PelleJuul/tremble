shape = 0.77;

n = 1000;
data = zeros(n*2, 1);
for i = 0:(n*2 - 1)
    j = mod(i, n) + 1;
    c1 = shape;
    c2 = 1 + (shape - 0.5);
    t = j / n;

    data(i + 1, 1) = sin(2 * pi * t * c1);
    data(i + 1, 2) = sin(2 * pi * t * c2 + c2 * 2 * pi);
end

subplot(2, 1, 1);
plot(data(:, 1));
ylim([-1 1]);
grid on;
subplot(2, 1, 2);
plot(data(:, 2));
ylim([-1 1]);
grid on;