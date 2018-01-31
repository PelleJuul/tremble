depth = 0.5;
phase = pi * 1.25;
speed = 4.0;
fs = 44100;
t = (0:fs) / fs;
a = 1 - depth * 0.5 * (1 + sin(2 * pi * speed * t + phase));
plot(t, a);
ylim([0 1]);