predicates
	parent(STRING, STRING)
	male(STRING)
	female(STRING)
	married_couple(STRING, STRING)
	father(STRING, STRING)%A1
	sister(STRING, STRING)
	aunt(STRING, STRING)%A11
	brother(STRING,STRING)
	sibling(STRING, STRING)
	first_cousin(STRING, STRING)
	second_cousin_brother(STRING, STRING)%B7
	any_cousin_sibling(STRING, STRING, INTEGER)
	any_cousin_brother(STRING, STRING, INTEGER)%B24
	husband(STRING, STRING)%C1
clauses
	parent("Khurshid", "Laziz").
	parent("Guli", "Laziz").
	parent("Zamira", "Guli").
	parent("Zamira", "Guzel").
	parent("Aidar", "Guli").
	parent("Aidar", "Guzel").
	parent("Guzel", "Marat").
	parent("Mukhsim", "Zamira").
	parent("Mukhsim", "Zoya").
	parent("Zoya", "Zamir").
	parent("Zamir", "Ruslan").
	
	male("Khurshid").
	male("Laziz").
	male("Aidar").
	male("Marat").
	male("Mukhsim").
	male("Zamir").
	male("Ruslan").
	
	female("Guli").
	female("Guzel").
	female("Zamira").
	female("Zoya").
	
	married_couple("Khurshid", "Guli").
	married_couple("Aidar", "Zamira").
	
	
	father(X, Y):- parent(X, Y), male(X).%	-	-	-	-	-	-	-	-	A1
	
	sister(X, Y):- parent(Z, X), parent(Z, Y), female(X), not(X = Y).
	aunt(X, Y):- parent(Z, Y), sister(X, Z).%	-	-	-	-	-	-	-	A11
	
	%grandparent(X, Y):- parent(X, Z), parent(Z, Y).
	brother(X, Y):- parent(Z, X), parent(Z, Y), male(X), not(X = Y).
	sibling(X,Y):- brother(X,Y);sister(X,Y).
	first_cousin(X,Y):- parent(Z,X), sibling(A,Z), parent(A, Y).
	second_cousin_brother(X,Y):- parent(Z,X), first_cousin(A,Z), parent(A, Y).%	-	-	-	B7
	
	any_cousin_sibling(X, Y, 1):- sibling(X,Y).
	any_cousin_sibling(X, Y, N):- parent(Z1,Y), parent(C1, X), N1 = N-1, any_cousin_sibling(Z1, C1, N1).
	any_cousin_brother(X, Y, 1):- brother(X,Y).
	any_cousin_brother(X, Y, N):- male(X), parent(Z1,Y), parent(C1, X), N1 = N-1, any_cousin_sibling(Z1, C1, N1).%	B24
	
	husband(X,Y):- married_couple(X,Y), male(X).%	-	-	-	-	-	-	-	C1
goal
	%father("Khurshid", "Laziz").
	%aunt(X,"Laziz").
	%second_cousin_brother(X,"Laziz").
	%any_cousin_brother("Laziz","Marat",2).
	husband(X,Y).
	
	
	
	
	
	
	
	
	
	