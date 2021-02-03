domains
	list = integer*
predicates
	removeeven(list, list)
	isinside(integer, list)
	intersect(list, list, list)
clauses	
	removeeven([], []).
	removeeven([H|T], R):- 
    					H mod 2 = 0, !,
    					removeeven(T, R).
	removeeven([H|T], [H|Tr]):- 
    					removeeven(T, Tr).
    					
    	isinside(_,[]):- fail.
    	isinside(X, [X|_]):- !.
    	isinside(X, [_|T]):- isinside(X, T).
    	
    	intersect([],_,[]).
	intersect([H|T],Y,[H|R]) :- isinside(H,Y), intersect(T,Y,R), !.
	intersect([_|T],Y,R) :- intersect(T,Y,R).
goal
	%removeeven([1,2,3,4,5], X).
	intersect([0,2,3,4,6], [1,2,3,4,5],X).