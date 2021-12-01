all: Goodreads.out

Goodreads.out: Main.o Book.o GoodReads.o Author.o GeneralFunctions.o User.o Date.o Review.o
	g++ -std=c++11 Main.o Book.o GoodReads.o Author.o GeneralFunctions.o User.o Date.o Review.o -o Goodreads.out

Main.o: Main.cpp ImportantLibraries.hpp GeneralFunctions.hpp Date.hpp Review.hpp Book.hpp Author.hpp User.hpp GoodReads.hpp ReadingDefines.hpp WritingDefines.hpp
	g++ -std=c++11 -c Main.cpp

GoodReads.o: GoodReads.cpp ImportantLibraries.hpp GeneralFunctions.hpp Date.hpp Review.hpp Book.hpp Author.hpp User.hpp GoodReads.hpp ReadingDefines.hpp WritingDefines.hpp
	g++ -std=c++11 -c GoodReads.cpp

User.o: User.cpp ImportantLibraries.hpp GeneralFunctions.hpp Date.hpp Review.hpp Book.hpp Author.hpp User.hpp WritingDefines.hpp
	g++ -std=c++11 -c User.cpp

Author.o: Author.cpp ImportantLibraries.hpp GeneralFunctions.hpp Date.hpp Review.hpp Book.hpp Author.hpp WritingDefines.hpp
	g++ -std=c++11 -c Author.cpp

Book.o: Book.cpp ImportantLibraries.hpp GeneralFunctions.hpp Date.hpp Review.hpp Book.hpp WritingDefines.hpp
	g++ -std=c++11 -c Book.cpp

Review.o: Review.cpp ImportantLibraries.hpp GeneralFunctions.hpp Date.hpp Review.hpp WritingDefines.hpp
	g++ -std=c++11 -c Review.cpp

Date.o: Date.cpp ImportantLibraries.hpp GeneralFunctions.hpp Date.hpp WritingDefines.hpp
	g++ -std=c++11 -c Date.cpp

GeneralFunctions.o: GeneralFunctions.cpp ImportantLibraries.hpp GeneralFunctions.hpp WritingDefines.hpp
	g++ -std=c++11 -c GeneralFunctions.cpp

clean :
	rm *.o Goodreads.out
