COMPILER := gcc

#Add your File.c
C_FILES := ../project/Test.c
C_FILES += ../project/ADD_FA.c
C_FILES += ../project/ADD_FL.c
C_FILES += ../project/PRINT.c


#Add your File.o
O_FILES := Test.o 
O_FILES += ADD_FA.o
O_FILES += ADD_FL.o
O_FILES += PRINT.o


EXE_FILES := Linked_list.exe

all: clean linking

build: $(C_FILES)
	@$(COMPILER) -c $(C_FILES)
linking: build 	
	@$(COMPILER) $(O_FILES) -o $(EXE_FILES)
clean:
	rm -rf *.o *.exe