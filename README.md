# Clustering Data With Many Methods Cplusplus
This project was developed in the scope of the undergraduate course algorithmic problem solving of the NKUA. 
It includes 12 different implementations of clustering techniques from simple K-means to LSH/Hypercube clustering.

Each of the implemented algorithms includes 3 different steps. Initialization, Assignment and Update.

We provide hereby all the different combinations for the algorithmic implementation of each step:

## Initialization

1. Random selection of k points (simplest)
2. K-means++

## Assignment

1. Lloyd’s assignment
2. Assignment by Range search with LSH (εργασία 1)
3. Assignment by Range search with Hypercube (εργασία 1)

## Update
1. K-means
2. Partitioning Around Medoids (PAM) improved like Lloyd’s

In total we get 12 combinations.

## Run details

A makefile is included for compilation purposes and the program can be run by executing

./cluster -i input.csv -d euclidean -c cluster.conf -o out 
./cluster -i input.csv -d cosine -c cluster.conf -o out 

Where input.csv are the input data files in csv format and 
out is the filepath to the output that the programm will produce (you just need to state a name and the rest will be taken care of by the program)

cluster.conf is the file path to the configuration file for the program (a sample is provided)

The output file will contain for each cluster the indexes of the data belonging to it

Also a silhouette implementation is included for evaluation purposes.

Implementation was concluded in early 2019
