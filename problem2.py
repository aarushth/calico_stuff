import math
from copy import deepcopy
def solve(num_coord, x_coords, y_coords):
    min_x = x_coords[0]
    max_x = x_coords[0]
    min_y = y_coords[0]
    max_y = y_coords[0]

    for i in range(num_coord):
        if x_coords[i] < min_x: min_x = x_coords[i]
        if x_coords[i] > max_x: max_x = x_coords[i]
        if y_coords[i] < min_y: min_y = y_coords[i]
        if y_coords[i] > max_y: max_y = y_coords[i]
    
    return (max_x - min_x)*(max_y-min_y)

def main():
    T = int(input())
    for i in range(T):
        min_area = math.inf
        num_coord = int(input())
        x_coords = []
        y_coords = []
        # puts the str input into 2 arrays: array of x coord and y coord
        for i in range(num_coord):
            m = input()
            l = m.split()
            x_coords.append(float(l.pop(0)))
            y_coords.append(float(l.pop(0)))

        slopes = []
        copy_y = deepcopy(y_coords)
        copy_y.sort(reverse=True)
        copy_y = copy_y[0:4]
        for i in copy_y:
            for j in copy_y:
                if i == j: continue
                if x_coords[y_coords.index(j)] - x_coords[y_coords.index(i)] == 0:
                    slopes.append(0)
                    continue
                slopes.append(
                    (j-i)/(x_coords[y_coords.index(j)] - x_coords[y_coords.index(i)])
                )
        degree = 0 
        for i in range(4):
            for j in range(i+1, 4):
                if slopes[i] == slopes[j]:
                    degree = math.degrees(math.atan(-1*slopes[i]))

        for k in range(num_coord):
            x = x_coords[k]
            y = y_coords[k]
            x_coords[k] = (x*math.cos(math.radians(degree))) - (y*math.sin(math.radians(degree)))
            y_coords[k] = (x*math.sin(math.radians(degree))) + (y*math.cos(math.radians(degree)))

        print(degree)
        print(solve(num_coord, x_coords, y_coords))

        # rotates by 1 degree each time and finds min bounding box area
        # while degree <= 90:
        #     x_c = deepcopy(x_coords)
        #     y_c = deepcopy(y_coords)
        #     for k in range(num_coord):
        #         x = x_c[k]
        #         y = y_c[k]
        #         x_c[k] = (x*math.cos(math.radians(degree))) - (y*math.sin(math.radians(degree)))
        #         y_c[k] = (x*math.sin(math.radians(degree))) + (y*math.cos(math.radians(degree)))
        #     if solve(num_coord, x_c, y_c) < min_area:
        #         min_area = solve(num_coord, x_c, y_c)

        #     degree += 0.1

        
main()
