This code allows you to get all alignments in a square matrix
for any matrix size and number of symbols. 
Those alignments are retrieved as follows:
    - lines correspond to the alignment's length
    - columns represent the number of alignments for a symbol

For example, the next three by three square matrix gives:
    (matrix)
        1  1  1 
        0  0  1 
        1  0  0
    (alignment)
        2  5  3     Alignment of two symbols: 5 for zeros and 3 for ones 
        3  0  1     Alignment of three symbols: 0 for zeros and 1 for ones


(NB) Only the longest alignments are considered: 
    
    0 0 0

        In this line there are one alignment of three zeros and two alignments of two but
        as the first alignment of two takes part of a longer alignment it is not considered
        
        Thus if you want the total number of alignments, you just have to add all the longer
        alignments


To modify the size of the square matrix or the number of symbols,
you can modify to the header.


All alignments are saved in "optAlign.csv".
