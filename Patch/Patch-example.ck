SinOsc sin => Pan2 pan => dac;

SinOsc lfo => Patch p => blackhole;
1 => lfo.freq;

p.connect(pan, "pan");

10::second => now;