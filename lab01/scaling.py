#!/usr/bin/env python

import subprocess
import os

output = open('scaling.csv','w')
output.write('key,value'+'\n')
output.close()

for i in [1,10,1e2,1e3,1e4,1e5,1e6,1e7,1e8]:
	cmd = 'echo ' + str(i) + ' | ./triad'
	tmp = subprocess.Popen(cmd, shell=True,
			stdout=subprocess.PIPE)
	tmp.wait()
	out, err = tmp.communicate()

	output = open('scaling.csv','a')
	for  o in out.split('\n'):
	     if len(o.split()) > 1:
		print o.split()[1], o.split()[3]
		output.write(o.split()[1]+','+o.split()[3]+'\n')

