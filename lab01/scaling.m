% matlab file for plotting the Janus performance benchmark
semilogx(key, value, '--rs')
xlabel('Length')
ylabel('Speed (MFLOP/s)')
title(sprintf('Performance vs Array size \nIntel Xeon CPU X5660 @ 2.80GHz 12288 KB Cache'))
