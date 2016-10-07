proj: proj1.o
	gcc proj1.o -o proj
proj1.o: proj1.c

test: test1 test2 test3 test4 test5 test6


test1:
	./proj 1 PIZZAPIE data.txt encryptedFile1.txt
test2:	
	./proj 2 PIZZAPIE encryptedFile1.txt decryptedFile1.txt
test3: 
	diff -s data.txt decryptedFile1.txt

test4: 
	./proj 1 HELLOWORLD data2.txt encryptedFile2.txt
test5: 
	./proj 2 HELLOWORLD encryptedFile2.txt decryptedFile2.txt
test6: 
	diff -s data2.txt decryptedFile2.txt
