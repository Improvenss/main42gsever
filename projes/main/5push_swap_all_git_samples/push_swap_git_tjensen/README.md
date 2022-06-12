# 42-push_swap

The program push_swap will sort random integers on a stack, with a limited set of instructions, trying to use the least stack operations to get an ascending sorted stack.

## How to use it
0. Clone the repo
1. Call ```make release```
3. Start program with your own input: ```./push_swap [put your args seperated by spaces]```
4. Start program with 500 random ints: ```./push_swap `ruby -e "puts (0..499).to_a.shuffle.join(' ')"` ```

## "Game Rules"

<b>The game is composed of 2 stacks named A and B.</b>

<b>Starting Point:</b>
- Stack_A contains random numbers of either positive or negative numbers without any duplicates.
- Stack_B is empty

<b>The goal is to sort in ascending order numbers into stack.</b>

<b>The operations the program can do, are limited to the following set:</b>

| Operations    | Description                                                                           |
| ------------- | --------------------------------------------------------------------------------------|
| <b>sa</b>     | swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements) |
| <b>sb</b>     | swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements) |
| <b>ss</b>     | sa and sb at the same time |
| <b>pa</b>     | push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty |
| <b>pb</b>     | push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty |
| <b>ra</b>     | rotate a - shift up all elements of stack a by 1. The first element becomes the last one |
| <b>rb</b>     | rotate b - shift up all elements of stack b by 1. The first element becomes the last one |
| <b>rr</b>     | ra and rb at the same time |
| <b>rra</b>    | reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one |
| <b>rrb</b>    | reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one |
| <b>rrr</b>    | rra and rrb at the same time |


<hr>

### Sample sorting animation for 100 integers:

*Visualized with the great push_swap [visualizer](https://github.com/o-reo/push_swap_visualizer) from [o-reo](https://github.com/o-reo). I really appreciate this visualiser, it helped a lot to find strange behaviour of the sorting algorithms. 

![push_swap-animation](https://user-images.githubusercontent.com/56789534/137463054-e642a7d5-711d-4f25-bf55-03b47d8fcfc3.gif)

<hr>
<b>*All 42 projects must be written in C (later C++) in accordance to the 42 School Norm.<br></b>
<br>

> #### Sample restrictions:
> - All variables have to be declared and aligned at the top of each function
> - Each function can not have more then 25 lines
> - Projects should be created with allowed std functions otherwise it is cheating
