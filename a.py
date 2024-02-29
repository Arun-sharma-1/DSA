import random
import pyautogui as pg
import time
animal = ('gandu','lodu','bsdk')
time.sleep(5)
for i in range(500):
    a = random.choice(animal)
    pg.write(a)
    pg.press('enter')