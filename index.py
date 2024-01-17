import os
import time
import sys

LINE = "------------------------------------------------"
REALPASSWORD = "12345"

def PrintHeader(txt: str):
    header = txt.center(len(LINE))
    print(f'{LINE}\n{header}\n{LINE}')

def Calculator(num1: int, num2: int, method: str) -> int:
    if method == '+': return num1 + num2
    if method == '-': return num1 - num2
    if method == 'x': return num1 * num2
    if method == 'div': return num1 / num2
    if method == 'mod': return num1 % num2
    return 0

def MainMenu():
    try:
        PrintHeader(f'You are now successfully logged in.')
        print(f'1. +\n2. -\n3. x\n4. div\n5. mod\n6. Exit\n{LINE}')
        selected = int(input("Input the number ==> "))
        if selected == 6: os.system("cls"); PrintHeader("<<< Bye Bye >>>"); time.sleep(5); sys.exit(0)
        if selected == 1 or selected == 3:
            os.system("cls")
            PrintHeader(f'Select to choice ==> {1 if selected == 1 else 3}')
            Inum1 = int(input("Input Number 1 [1-10] ==> "))
            Inum2 = int(input("Input Number 2 [1-10] ==> "))
            if(Inum1 < 1 or Inum1 > 10): return os.system("cls"); MainMenu()
            if(Inum2 < 1 or Inum2 > 10): return os.system("cls"); MainMenu()
            res = f'{Inum1} {"+" if selected == 1 else "x"} {Inum2} = {Calculator(Inum1, Inum2, "+" if selected == 1 else "x")}'
            PrintHeader(res)
            MainMenu()
        elif selected == 2 or selected == 4 or selected == 5:
            os.system("cls")
            PrintHeader(f'Select to choice ==> {2 if selected == 2 else 4 if selected == 4 else 5}')
            Inum1 = int(input("Input Number 1 [1-10] ==> "))
            Inum2 = int(input("Input Number 2 [1-10] ==> "))
            if(Inum1 < 1 or Inum1 > 10): return os.system("cls"); MainMenu()
            if(Inum2 < 1 or Inum2 > 10): return os.system("cls"); MainMenu()
            if Inum1 < Inum2:
                res = f'{Inum2} {"-" if selected == 2 else "div" if selected == 4 else "mod"} {Inum1} = {Calculator(Inum2, Inum1, "-" if selected == 2 else "div" if selected == 4 else "mod")}'
                PrintHeader(res)
            else:
                res = f'{Inum1} {"-" if selected == 2 else "div" if selected == 4 else "mod"} {Inum2} = {Calculator(Inum1, Inum2, "-" if selected == 2 else "div" if selected == 4 else "mod")}'
                PrintHeader(res)
            MainMenu()
        else:
            os.system("cls")
            MainMenu()

    except:
        os.system("cls")
        MainMenu()

def CheckPassword():
    attemps = 0
    while(attemps < 3):
        try:
            InputPass = str(input("Input the password ==> "))
            if(InputPass != REALPASSWORD): 
                attemps += 1
                print(f'[Warning] Input password at {attemps} no correct.')
            else:
                os.system("cls")
                MainMenu()
                break
        except:
            os.system("cls")
            main()

def main() -> int:
    PrintHeader("Welcome")
    CheckPassword()
    return 0

if __name__ == "__main__":
    main()
