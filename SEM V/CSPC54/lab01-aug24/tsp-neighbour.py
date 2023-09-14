import math

def solve_tsp_nearest(distances):
    num_cities = len(distances)
    visited = [False] * num_cities
    tour = []
    total_distance = 0
    
    # Start at the first city
    current_city = 0
    tour.append(current_city)
    visited[current_city] = True
    
    # Repeat until all cities have been visited
    while len(tour) < num_cities:
        nearest_city = None
        nearest_distance = math.inf

        # Find the nearest unvisited city
        for city in range(num_cities):
            if not visited[city]:
                distance = distances[current_city][city]
                if distance < nearest_distance:
                    nearest_city = city
                    nearest_distance = distance

        # Move to the nearest city
        current_city = nearest_city
        tour.append(current_city)
        visited[current_city] = True
        total_distance += nearest_distance

    # Complete the tour by returning to the starting city
    tour.append(0)
    total_distance += distances[current_city][0]

    return tour, total_distance

distances=[
    [0, 255, 504, 477, 423],
    [255, 0, 612, 356, 392],
    [504, 612, 0, 456, 304],
    [477, 356, 456, 0, 152],
    [423, 392, 304, 152, 0]]
for row in distances:
    print(row)

tour, total_distance = solve_tsp_nearest(distances)

print("Tour: ", tour)
print("Total distance: ", total_distance)