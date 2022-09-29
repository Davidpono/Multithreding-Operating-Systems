# Multithreding-Operating-Systems
Santa Claus
Santa Claus sleeps in his shop up at the North pole, and can only be wakened up by either all nine reindeers being back from their year long vacation on the beaches of some tropical island in the South Pacific, or by some elves who are having some difficulties making the toys.

One elf's problem is never serious enough to wake up Santa (otherwise, he may never get any sleep). So, the elves visit Santa in a group of three. When three elves are having their problems solved, any other elves wishing to visit Santa must wait for those elves to return. If Santa wakes up to find three elves waiting at his shop's door, along with the last reindeer having comeback from the tropics, Santa has decided that the elves can wait until after Christmas, because it is more important to get his sleigh ready as soon as possible. It is assumed that the reindeers don't want to leave the tropics, and therefore they stay there until the last possible moment. They might not even come back, but since Santa is footing the bill for their year in paradise. This could also explain the quickness in their delivering of presents, since the reindeers cannot wait to get back to where it is warm. The penalty for the last reindeer to arrive is that it must get Santa while the others wait in a warming hut before being harnessed to the sleigh.

Here are some specifics. For each elf, he waits for two more elves in order to wake up Santa. A group of three elves submit their problems to Santa and wait until their problems are answered. Then, go back to work until a new problem comes up.

For each reindeer, it tans on the beaches for some time and returns to paradise. If all reindeers (say 9) have returned, the last (i.e., the 9th) one wakes up Santa and all nine wait to be attached to the sleigh. Then, fly off to deliver the toys and head back to the Pacific island.

The Santa takes some rests until (1) all reindeers have come back or (2) there are three elves posting questions. If it is the first case, Santa calls up all reindeer except the one who waked Santa up, setup sleigh for each reindeer. Then, the team flies off to deliver toys for a while and returns. Finally, release all reindeers. If it is the second case, Santa lets all three elves in and solves the (three) problems that the elves bring in. After solving the problem, Santa goes in bed again!

Well, Santa may want to take a long vacation as everybody does. So, Santa has made a decision that after delivering toys for some number of times (say 10), he will lay off all elves and reindeers and call for a quit. That is why you have not received toys from Santa for many years!

Each elves is a thread with the following pattern:

while (1) {
     Delay();                 // make toys
     AskQuestion(...);        // encounter a problem
     Delay();                 // problem solved, take a rest
}
AskQuestion() is a function. When an elf has a question, he calls AskQuestion(), which blocks the calling elf until a gang of three is possible. When the control returns, the question is answered.

The following shows a reindeer thread:

while (1) {
     Delay();                 // tan on the beaches
     ReindeerBack(...);       // report back to Santa
     WaitOthers(...);         // wait for others
                              // Don't forget: the last wakes up Santa
     WaitSleigh(...)          // wait for attaching sleigh
     FlyOff(...);             // fly off to deliver toys
                              // Santa will let go all reindeers
     Delay();                 // prepare for vacation
}
ReindeerBack(), WaitOthers(), WaitSleigh() and FlyOff() are all functions. Reindeers come back one by one. When it comes back, it calls ReindeerBack() to register this event. Then, it calls WaitOthers() to wait for the other reindeers. Keep in mind that the last reindeer must wake up the Santa. After a reindeer returns from the call to WaitOthers(), all reindeers will act as a group. Next, all reindeers call WaitSleigh(), waiting to be attached to a sleigh. Again, all reindeers act as a single group. Once this step completes, all reindeers fly off as a single group to deliver toys.

The Santa thread looks like the following:

while (not retire) {
     Sleep(...);              // take a nap
                              // wakened up by elves or the last reindeer
     what is the reason?      // note that toy delivering is more important
     if (all reindeers are back) { // delivery has a higher priority
          // gather all reindeers
          // put on sleigh
          // and fly off
          Delay();            // Santa delivers toys
          // release all reindeer for vacation
     }
     if (elves have a question) { // there many be a # of groups waiting
          // let elves in
          Delay();            // solve their problem
          // solve the problem and release elves
     }
}
Santa sleeps first with function Sleep(), which means he is blocked until three elves ask questions, or the last reindeer wakes him up. Santa always takes care the reindeers first. If Santa is wakened up by the last reindeer, he releases all waiting reindeers. Santa waits all reindeers are there. Then, he attaches the sleigh (this is the reason that all reindeers must act as a single group). After the sleigh is attached, Santa and reindeers fly off. On the other hand, if Santa is wakened up by elves, he takes some time to solve the problem, and releases all three elves.

Your implementation must correctly handle the following important situations:

Only exactly three elves can form a group and ask questions.
Before the problem is solved, no other elves can leave. While three elves are waiting for the answers, no other elves can cut in.
Santa answers questions only if he is not sleeping, of course!
When Santa is wakened up by a reindeer, this one must be the last reindeer who just came back. Only the last reindeer can wake up the Santa.
Santa always takes care reindeers first.
While Santa is attaching sleigh and delivering toys, all reindeers must be there.
Write a C++ program using ThreadMentor to simulate these activities. Note that you can only use mutex locks and semaphores. Your program will not be counted as a correct one if any other synchronization primitives are used.
Input and Output
The input of your program consists of the following:

The number of elves e, the number of reindeers r, and the number of toy deliveries t should be taken from the command line arguments as follows:
prog2  e  r  t
Thus, prog2  7  9  8 means Santa's shop has 7 elves and 9 reindeers. After delivering toys 8 times, Santa retires. If e is 0, the default value is 7; if r is 0, the default value is 9; and if t is 0, the default value is 5. For example, prog2  0  6  0 means that Santa's shop has 7 elves and 6 reindeers. After delivering toys 5 times, Santa retires. All command line arguments are non-negative.
Your program should generate an output similar to the following:
Santa thread starts
     .....
     Reindeer 3 starts
     .....
          Elf 6 starts.
     .....
     Reindeer 1 returns
          Elf 2 has a problem
          Elf 5 has a problem
          Elf 1 has a problem
     Reindeer 3 returns
          Elves 1, 2, 5 wake up the Santa
Santa is helping elves
          Elf 7 has a problem
     Reindeer 2 returns
Santa answers the question posted by elves 1, 2, 5
          Elves 1, 2, 5 return to work
             ..........
     The last reindeer 5 wakes up Santa
Santa is preparing sleighs
          Elf 4 has a problem
             ..........
The team flies off (1)!  // the number indicates how many toy deliveries 
          Elf 2 has a problem
             ..........
After (XX) deliveries, Santa retires and is on vacation!
Due to the dynamic behavior of multithreaded programs, you will not be able to generate an output that is exactly identical to the above.
All messages from the Santa thread start on column 1; all messages generated by reindeer threads start on column 5; and all messages printed by elf threads start on column 10. Without observing this rule, you may risk lower grade.
The output below illustrates that elves 2, 5 and 1 have problems and form a group. They wake up Santa. Then, Santa answers their questions and release them. After this, the elves go back to work and the Santa goes back to sleep.
          Elf 2 has a problem
          Elf 5 has a problem
          Elf 1 has a problem
          ..........
          Elves 1, 2, 5 wake up the Santa
          ..........
Santa answers the question posted by elves 1, 2, 5
          ..........
          Elves 1, 2, 5 return to work
The following illustrates the interaction between reindeers and the Santa. Reindeers return one by one. The last one, reindeer 5 here, wakes up Santa. Then, Santa prepares the sleigh. After this, the team flies off. The number in parenthesis is the number of toy deliveries.
     Reindeer 1 returns
     ..........
     Reindeer 3 returns
     ..........
     Reindeer 2 returns
     ..........
     The last reindeer 5 wakes up Santa
     ..........
Santa is preparing sleighs
     ..........
The team flies off (1)!
After a specific number of toy deliveries, Santa prints out a message and stops his toy-making operation.
After (XX) deliveries, Santa retires and is on vacation!


Submission Guidelines
All programs must be written in ANSI C++.
Use the submit command to submit your work. You can submit as many times as you want, but only the last one will be graded. A makefile without visual is required. Name your executable prog2.
I will use the following approach to compile and test your programs:
make                <-- make your program
prog2 e r t         <-- test your program
I will repeat the above procedure several times with different command line arguments to see if your program performs correctly.
Your implementation should fulfill the program specification as stated. Any deviation from the specification will cause you to receive zero point.
You should aim for maximum parallelism. That is, implement the solution as stated and make sure all required threads will execute simultaneously. Without doing so, you risk very low grade.
No late submission will be graded.
My rule of grading is deduction based. I assume you always receive 100%. If you missed something, some points will be taken off based on the following rules. Read these rules carefully. Otherwise, you could receive low or very low grade. Click here to see how your program will be graded.
Your programs must contain enough comments. Programs without comments or with insufficient comments will cost you 30%.
For each program, the first piece should be a program header to identify yourself like this:
// ----------------------------------------------------------- 
// NAME : John Smith                         User ID: xxxxxxxx 
// DUE DATE : mm/dd/yyyy                                       
// PROGRAM ASSIGNMENT #                                        
// FILE NAME : xxxx.yyyy.zzzz (your unix file name)            
// PROGRAM PURPOSE :                                           
//    A couple of lines describing your program briefly        
// ----------------------------------------------------------- 
For each function in your program, include a simple description like this:

// ----------------------------------------------------------- 
// FUNCTION  xxyyzz : (function name)                          
//     the purpose of this function                            
// PARAMETER USAGE :                                           
//    a list of all parameters and their meaning               
// FUNCTION CALLED :                                           
//    a list of functions that are called by this one          
// ----------------------------------------------------------- 
Bad programming style and missing headers will cost you 30%.

Submit a one-page description of your solution, discussing the following issues:
The logic of your program

Why does your program work?

Convince me that your program works properly. More precisely, answer the following questions. Make sure you will have a convincing argument for each question. Note that argument such as "because a semaphore is used to ....., the indicated situation cannot happen" will not be counted as convincing. You should explain why the situation will not happen through the use of a semaphore or semaphores. Providing arguments like that will receive low or very low grade. To enforce good and convincing arguments for this exercise, the maximum deduction assigned to your README is increased to 50%.
How do you guarantee that only three elves will ask questions?

Show that why no elf will leave before the questions are answered.

Show that while three elves are waiting for an answer, no other elves can cut in and ask questions.

How do you guarantee that Santa only answers question while he is not sleeping.

Show that when Santa is wakened up by a reindeer, this reindeer is the last one coming back from vacation.

How do you make sure Santa always handles reindeers first.

Show that while Santa is attaching the sleigh and delivering toys, all reindeers are there. They won't sneak out for vacation.

Show that while Santa is attaching the sleigh and delivering toys, elves will not ask questions.

You will receive very low grade if this file contains a direct statement-by-statement translation of your program.

Name this file README rather than readme or Readme. Spell check this file; otherwise, you may risk lower grade.

Missing README costs you 50%, poorly written README costs you 50%, and submitting a non-text file costs you 30%.

Not-compile programs receive 0 point. By not-compile, I mean any reason that could cause an unsuccessful compilation, including missing files, incorrect filenames, syntax errors in your programs, incorrect makefile and so on. Double check your files before you submit, since I will not change your program to make it work.

Compile-but-not-run programs receive no more than 50%.

Compile-but-not-run means you have attempted to solve the problem to certain extent but you failed to make it working properly. A meaningless or vague program receives no credit even though it compiles successfully. Another common problem is that your makefile could successfully process your source files (i.e., compiled successfully); but, your makefile does not generate an executable file with the desired filename (i.e., prog2 in this assignment). If this happens, I will consider your submission as compile-but-not-run.

Programs delivering incorrect result, incomplete result, or incompatible output receive no more than 70%.

Each race condition, busy waiting, or deadlock costs you 10%.

All deductions mentioned above are cumulative! This means that even though you have turned in a correct program, you could get very low grade. For example, if your submission does not have the necessary program and function headings (30% off), does not have enough comments (30% off), compiles but not runs correctly (30% off), and contains a race condition, then you will receive 60×(100-30-30-30-10)%=0 points.

Programs submitted to wrong class and/or wrong sections will not be graded.

Your submission should include the following files:

File thread.h that contains all class definitions of your threads.

File thread.cpp contains all class implementations of your threads.

File thread-support.cpp contains all supporting functions such as AskQuestion(), ReindeerBack(), WaitOthers(), WaitSleigh(), FlyOff(), Sleep() and other functions designed and implemented by you as needed.

File thread-main.cpp contains the main program.

File Makefile is a makefile that compiles the above three files to an executable file prog2. Since we may use any lab machine to grade your programs, your makefile should make sure all paths are correct. Note also that without following this file structure your program is likely to fall into the compile-but-not-run category, and, as a result, you may get a low grade. Before submission, check if you have the proper file structure and correct makefile. Note that your Makefile should not activate the visualization system.

File README.

Always start early, because I will not grant any extension if your home machine, your phone line or the department machine crashes in the last minute.

Since the rules are all clearly stated above, no leniency will be given. So, if you have anything in doubt, please ask for clarification
