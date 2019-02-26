all: 2.20-Circle.exe 2.23-LargestSmallest.c 2.32-BMICalculator.exe 5.32-GuessTheNumber.exe 6.19-DiceRolling.c 4.28-PayCalculator.exe 8.11-RandomSentences.exe 9.10-Temperatures.exe 9.11-EscapeSequences.exe 7.30-CircleMathWFunctionPointers.exe MathPracticeProject.exe ProjectMenu.exe

2.20-Circle.exe:
	gcc 2.20-Circle.c -o 2.20-Circle.exe
2.23-LargestSmallest.exe:
	gcc 2.23-largest_smallest.c -o 2.23-largest_smallest.exe
2.32-BMICalculator.exe:
	gcc 2.32-BMICalculator.c -o 2.32-BMICalculator.exe
5.32-GuessTheNumber.exe:
	gcc 5.32-GuessTheNumber.c -o 5.32-GuessTheNumber.exe
6.19-DiceRolling.exe:
	gcc 6.19-DiceRolling.c -o 6.19-DiceRolling.exe
4.28-PayCalculator.exe:
	gcc 4.28-PayCalculator.c -o 4.28-PayCalculator.exe
8.11-RandomSentences.exe:
	gcc 8.11-RandomSentences.c -o 8.11-RandomSentences.exe
9.10-Temperatures.exe:
	gcc 9.10-Temperatures.c -o 9.10-Temperatures.exe
9.11-EscapeSequences.exe:
	gcc 9.11-EscapeSequences.c -o 9.11-EscapeSequences.exe
7.30-CircleMathWFunctionPointers.exe:
	gcc 7.30-CircleMathWFunctionPointers.c -o 7.30-CircleMathWFunctionPointers.exe
MathPracticeProject.exe:
	gcc MathPracticeProject.c -o MathPracticeProject.exe
ProjectMenu.exe:
	gcc ProjectMenu.c -o ProjectMenu.exe

clean:
	rm -rf *.exe
