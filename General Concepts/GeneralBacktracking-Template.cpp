#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
//     // General backtracking template
//     void backtrack(State state)
//     {

//         // Base case: if solution is complete
//         if (isComplete(state))
//         {
//             process(state); // handle the solution (e.g., print/store)
//             return;
//         }

//         // Try every possible choice
//         for (choice : choices)
//         {

//             // Skip invalid choices
//             if (!isValid(choice))
//                 continue;

//             // Make the choice
//             makeChoice(choice);

//             // Explore further with this choice
//             backtrack(newState);

//             // Undo the choice (backtrack)
//             undoChoice(choice);
//         }
//     }
// };