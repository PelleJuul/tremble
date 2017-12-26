r = 0.5;
f = 4.0;
fs = 44100;
n = fs;
T = (1:n) / fs;
Yp = 0;
Ym = 0;
fp = 1 / (2 * r);
fm = 1 / (2 * (1 - r));
p = r / (1 - r);
a = fm / fp;
s = 1;

if a > 1
    s = 1 / a;
end

for i = 1:n
  t = mod(T(i), 2 * pi);
  w = mod(2 * pi * f * t, 2 * pi);
  
  if w < 2 * pi * r
      Yp(i) = sin(w * fp) * a * s;
  else
      Yp(i) = -sin(w * fm - pi * p) * s;
  end
end

plot(T, Yp);
grid on;