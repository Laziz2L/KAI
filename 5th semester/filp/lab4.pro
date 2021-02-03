predicates
	parent(STRING, STRING)
	male(STRING)
	female(STRING)
	father(STRING, STRING)
	sister(STRING, STRING)
	grandparent(STRING, STRING)
clauses
	parent("Khurshid", "Laziz").
	parent("Guli", "Laziz").
	parent("Zamira", "Guli").
	parent("Zamira", "Guzel").
	parent("Aidar", "Guli").
	parent("Aidar", "Guzel").
	
	male("Khurshid").
	male("Laziz").
	male("Aidar").
	
	female("Guli").
	female("Guzel").
	female("Zamira").
	
	father(X, Y):- parent(X, Y),male(X).
	sister(X, Y):- father(Z, X), father(Z, Y), female(X), not(X = Y). 
	grandparent(X, Y):- parent(X, Z), parent(Z, Y).
goal
	%Is Laziz the son of Khurshid?
	%parent("Khurshid", "Laziz"),male( "Laziz").
	
	%Is Guli a grandmother?
	%grandparent("Guli",_),female("Guli").
	
	%Who are the sisters of Guli?
	%write("Guli's sisters are:"), nl, sister(X,"Guli"), write(X), nl, fail.
	
	%Is Zamira mother or daughter of Guzel?
	parent("Zamira", "Guzel"), write("Zamira is Guzel's mother."), nl; parent("Guzel", "Zamira"),write("Zamira is Guzel's daughter."),nl.
