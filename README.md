# **LEM-IN**

### project description
* The goal of this project is to find the quickest way to get n ants across the farm.
* Quickest way means the solution with the least number of instructions.
* All ants can move one nodes in one instruction
* The ants have to avoid traffic jams as well as walking all over their fellow ants.
* ##start and ##end node can contain as many ants as necessary
* However, other nodes can contain one ant at a time

### Video
[![](https://img.youtube.com/vi/_3_kpKwUh3Y/0.jpg)](https://www.youtube.com/watch?v=_3_kpKwUh3Y)
* green node is the start node
* blue node is the end node
* white nodes are the other nodes
* red circles are the ants

### example of a valid map
#number of ants  
3  
#all the nodes of the map  
0 843032 406853  
1 933097 592372  
2 421796 393782  
3 619072 45571  
4 958447 633433  
5 111781 892302  
6 113132 347210  
7 659759 152753  
##end  
end 995766 669954  
##start  
start 705984 615879  
#edges to connect the nodes    
1-end  
2-6  
4-7  
6-start  
3-start  
1-5  
7-2  
2-1  
5-4  
start-2  

### installation and execution
make  
./lem-in < map  
to run visualizer:  
./lem-in < map | ./visualizer  

SDL and OpenGL is used to implement visualizer for the filler.  
SDL, OpenGL & pkg-config has to be installed to compile & execute visualizer
