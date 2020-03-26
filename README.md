# setLinked

In the program I present the implementation of a mathematical set using linked lists (orderly). 
It also calculates the computational complexity of the element adding operation (two cases) and draws charts (using gnuplot). 

### Technologies
* C++ 11
* gnuplot


### Possible operations
Thanks to this program, it's possible to:
* add elements to the set
* delete elements from the set
* check if the set contains an element
* calculate an intersection of two sets
* calculate an union of two sets
* calculate a difference of two sets
* check if both sets are the same

### Setup
To run this program, download these files:
* ```computationalComplexity.cpp```
* ```example.cpp```
* ```setLinked.cpp```
* ```run```
* ```chartAscending```
* ```chartDescending```

and put them into one folder. Then use a command:
```ssh
$ ./run
```
The main part of this project is implementation of the set using linked lists and can be found in ```setLinked.cpp```.

### Example of use

![example](./examples(png)/example.png)

### Computational complexity
This program also calculates the computational complexity of the element adding operation.
It's important to consider two cases - when adding elements ascending and descending.
* #### Ascending
In this case, the complexity is O(n^2) (square time). The set is ordered in ascending order. When trying to insert a larger element, it's necessary to check all elements that the set already contains.

Chart based on program results (drawn with gnuplot):

![ascending](./examples(png)/chartAscending.png)


* #### Descending
In this case the complexity is O(n) (linear time). Each element added (except the first, of course) is smaller than the first element in the set.
Therefore, a new element is always added at the beginning of the set and it's not necessary to check all the elements.

Chart based on program results (drawn with gnuplot):

![ascending](./examples(png)/chartDescending.png)


### Additional information
* Program creates two files needed to draw a chart: ```ascending``` and ```descending``` 

