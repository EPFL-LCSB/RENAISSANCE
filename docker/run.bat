docker run 	--rm -it --gpus all	^
		-v %CD%\work:/home/renaissance/work 	^
		-v %CD%/..:/renaissance		^
		renaissance_docker 
