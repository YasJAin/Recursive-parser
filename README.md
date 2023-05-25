# Recursive-parser
THE FILE CONTAINS THE CODE FOR THE RCURSIVE PARSER BASED ON THE REQUIRED GRAMMAR

E -> TE'
E' -> +TE' | ε
T -> FT'
T' -> *FT' | ε
F -> (E) | id

The recursive parser takes in an input string and sends the status regarding whether or not the string is accepted with respect to the given grammar. 
