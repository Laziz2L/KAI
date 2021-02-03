domains
	Jockey = STRING
	Horse = STRING
	Race = STRING

facts - Hippodrome
	j_horse(Jockey, Horse)
	race_winner(Race, Jockey)

predicates
	switch(INTEGER).
	menu.
clauses
	switch('0'):- write("End.").
	switch('1'):- 
		write('\10', "Jockey> "), readln(J),
		write('\10', "Horse> "), readln(H),
		assert(j_horse(J, H)), menu.
	switch('2'):- 
		write('\10', "Race> "), readln(R),
		write('\10', "Jockey> "), readln(J),
		assert(race_winner(R, J)), menu.
	switch('3'):-  
		write('\10', "Jockey> "), readln(J),
		retract(j_horse(J,_)), menu.
	switch('4'):- 
		write('\10', "Race> "), readln(R),
		retract(race_winner(R,_)), menu.
	switch('5'):- 
		write('\10', "Jockey> "), readln(J),
		retract(j_horse(J,_)),
		write('\10', "New horse> "), readln(H),
		assert(j_horse(J, H)), menu.
	switch('6'):- 
		write('\10', "Race> "), readln(R),
		retract(race_winner(R,_)),
		write('\10', "New jockey> "), readln(J),
		assert(race_winner(R, J)), menu.
	switch('7'):- 
		save("C:\\Users\\lazzi\\Desktop\\db.txt", Hippodrome), nl, 
		write("Saving into the file - C:\\Users\\lazzi\\Desktop\\db.txt"), menu.
	switch('8'):- 
		consult("C:\\Users\\lazzi\\Desktop\\db.txt", Hippodrome),
		write("Reading from file - C:\\Users\\lazzi\\Desktop\\db.txt"), menu.
	switch('9'):- 
		j_horse(J, Count), write("Jockey: ", J), nl,write("Horse: ", Count), nl, nl, 
		race_winner(R,J),
		write("Race: ", R), nl,
		write("Winner:  ", J), nl, nl,
		fail, menu.
	switch(_):- write("Wrong symbol"), nl,menu.	
	menu:-  
		write('\10',"1 - add jockey/horse", '\10', "2 - add race winner",
			'\10', "3 - delete jockey",'\10', "4 - delete race winner",
			'\10', "5 - edit jockey",'\10', "6 - edit race winner",
			'\10', "7 - save into file",'\10', "8 - read from file",
			'\10', "9 - print all",'\10', "0 - exit"), nl,
		readchar(X), 
		switch(X).

goal
	menu, nl.