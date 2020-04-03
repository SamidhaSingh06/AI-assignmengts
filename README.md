#AI Assignments

/*
Assignment By - Samidha Singh
Roll no. - 1801152
*/

1. 8 queens problem : solved using ucs ( which boiled down to bfs due to uniform cost )

	Queens - represented by 1 and empty positions by 0

State Space:

	S (State Description) : { x1y1 , x2y2 , x3y3 , x4y4 , x5y5 , x6y6 , x7y7 , x8y8 }
                                where xiyi represents box where queen is placed, i -> 1 to 8
 
        I (Initial State) : { -1,-1,-1,-1,-1,-1,-1,-1 }
			    -1 represents queens outside of chessboard

        G (Goal test) : queens at non attacking position

        A (Actions) : move(q) where q -> queen

	C (Cost) : cost is 1 for each action


2. travelling salesman problem : solved using A* 
				 Heuristic : Minimum Spanning Tree + path to initial node

State Space:
	
	S (State Description) : <C1,C2,.....Cn>
				where Ci represents how many times a city is visited, n -> no. of cities, i -> 1 to n
	
	I (Initial State) : <1,0,.....0>
	
	G (Goal State) : <2,1,1,1,.....,1>
	
	A (Actions) : Explore(c) where c -> city


Heuristic:

	Minimum Spanning Tree + path back to initial city

	type : underestimating (admissible)

	proof of MST as underestimating heuristic: 

		MST gives least possible cost throughout the tree, so it represents the least possible way one can travel to all cities only once without getting into a cycle, and then path from last city to initial city is also being added to provide more accuracy on heuristic. Hence the optimum cost C* from initial state to Goal test is >=  h*(n) + g(n).

3. Clustering problem: solved using GA

	n students, k clusters and m subjects
	clustered them such that each cluster is having least diversity depending upon marks of each subject
	
4. AI vs Human AND AI vs AI: solved using Alpha-Beta Pruning
	
	
