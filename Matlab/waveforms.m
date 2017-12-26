%% Different waveforms

clear, close all

fs = 44100;

t = (0:44100-1)/fs;
f = 1;

deltaPhase = 2 * pi * f / fs;

phase = 0;
phaseVector = zeros(1,length(t));

for i=1:length(t)
    phase = phase + deltaPhase;
    phaseVector(i) = phase;
end

sineWave = sin(phaseVector);
squareWave = (phaseVector < pi) - (phaseVector > pi);
sawtoothWave = 1/pi*phaseVector - 1;
triangleWave = (phaseVector < pi) .* (-1+2/pi*phaseVector) + ...
    (phaseVector > pi) .* (3-2/pi*phaseVector);

figure
plot(t,sineWave,t,squareWave,t,sawtoothWave,t,triangleWave);


%% Change ratio between positive and negative half-period (sine)

fs = 44100;
posToNegRatio = 0.5;

t = (0:22050*posToNegRatio-1)/fs/posToNegRatio;
t1 = (22050:44100)/fs;

sin1 = sin(2*pi*f*t);
sin2 = sin(2*pi*f*t1);

sinTot = [posToNegRatio*sin1 sin2];

tPlot = (0:44100*2-1)/fs;
figure
plot(tPlot,[sinTot zeros(1,length(tPlot)-length(sinTot))]);

