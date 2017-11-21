import msvcrt

num = 0
done = False
while not done:
    print(num)
    num += 1

    if msvcrt.kbhit():
        print ("you pressed" + str(msvcrt.getch()) + "so now i will quit")
        done = True