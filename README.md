# Make-way-for-Ambulance-

## ABSTRACT ##

An ambulance which seems not to reach the patients on time and leads to the loss of their lives. 
Getting the shortest path to the ambulance as their guidance can make the work of the driver easier. The driver can reach the patients at a minimal time. 
This project is for a social cause which can help people in dire need of an ambulance at emergency.

## INTRODUCTION ##

An ambulance is a medically equipped vehicle which transports patients to treatment facilities, such as hospitals. Typically, out-of-hospital medical care is provided to the patient. Ambulances are used to respond to medical emergencies by emergency medical services.
Ambulance, a vehicle which when fast can save a priceless life in minutes. But this isn’t the reality. The sad part about this vehicle is that nowadays because of mushrooming traffic it can’t be fast as “FLASH”. Researching around the on-going scenario we found why not optimized the route for an ambulance. 
Coming to the title which is the heart of our project why not we make a path possible for the ambulance to reach the patient. We as a team have seen that most of the cases become critical just because of the time lag between the ambulance reaching to the patient and the hospital. So we thought of developing a model for the same.
When we look into this model not with an eye of the project rather see it with the eye of helping the society, we as a team feel that this really can help patients get the ambulance on the go irrespective of the rush hours on the roads. This could save patients who unfortunately lost their lives just because the ambulance couldn’t reach them in the appropriate time.

## RELATED WORK ## 


Google Maps shows most of the information about optimized paths which are also used by many services providing companies like Ola, Uber etc.
 Looking into some recent developments we could figure out some delivery agents using the same concepts of route optimization. 
We can take the example of Dominos (A food franchise) delivering food within 30 minutes. The delivery agent has thoughts trespassing their mind to find and implement the shortest path to reach from the brand outlet to the client’s address and many more.

## PROBLEM STATEMENT
    1. To find the best path for point to point reach of Ambulances.
    2. To compare the CPU runtime of algorithms such as Dijkstra, Bellman-Ford and Floyd Warshall.
    
## OBJECTIVE
Getting ambulance service on the patients on the go even in the rush hours to save their lives.
Patients don’t get the help of the ambulance during rush hours
Delay in the arrival of the ambulance to the hospital
Cases become critical due to time lag between incident spot to hospital

## ALGORITHM:-
    1. Our first step towards the project is to input a graph.
    2. On the graph that was passed, we applied 3 algorithms which were meant for finding the shortest path. 
    3. Algorithms that we chose were Dijkstra, Floyd Warshall and Bellman-Ford.
    4. Getting the CPU runtime to compare which gave the results fastest we used clock() function under the #include<time.h> header file.
    5. We created a menu for adding/ deleting nodes and edges in the graph.
    6. We lastly compared the CPU runtime manually and then concluded that the CPU runtime with the least amount of time consumed is the fastest.
    
   
