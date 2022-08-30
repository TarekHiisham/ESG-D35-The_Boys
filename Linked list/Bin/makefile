COMPILER := gcc

#Add your File.c
C_FILES := ../project/Test.c
C_FILES += ../project/ADD_FA.c

#Add your File.o
O_FILES := Test.o 
O_FILES += ADD_FA.o

EXE_FILES := Linked_list.exe

all: clean linking

build: $(C_FILES)
	@$(COMPILER) -c $(C_FILES)
linking: build 	
	@$(COMPILER) $(O_FILES) -o $(EXE_FILES)
clean:
	rm -rf *.o *.exe