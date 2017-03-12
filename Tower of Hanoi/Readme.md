# Tower of Hanoi Problem
Tower of Hanoi is a famous problem regarding use of recursive algorithm in solving puzzle.

### Problem Statement
    [![image](./Tower of Hanoi.png)](https://en.wikipedia.org/wiki/Tower_of_Hanoi)

There are three towers in Hanoi, one of them are full with **N-disc** (which we will refer as _**SOURCE**_ tower). We have to move those **N-disc** to another tower (mentioned as _**DESTINATION**_) and during this process we are allowed to use the third one (let us say _**VIA**_). But to make the process interesting, it is subjected to two constraints:
* You can move only one disc at a time.
* You cannot put larger disc over small one.

##### Note: N can be any positive integer, ranging from 1 to infinity.

### Analysis of the Problem
[![video](http://www.iros2012.org/site/sites/default/files/imgs/iros2012_TowerOfHanoiProblem.png)] (https://youtu.be/rVPuzFYlfYE)
So you remember we have three towers, namely _**SOURCE**_ Tower, _**DESTINATION**_ Tower and _**VIA**_ Tower. We have to take all the disc from SOURCE and put them to DESTINATION and can use VIA as temporary storage to maintain the given constraints.

#### Trivial Case: One disc in SOURCE tower
Okay let us solve the simplest version of the problem, the trivial case. What if there is only one disc in SOURCE tower? Then we can simply pop that out and put in DESTINATION tower, as simple as that.
```
    Move Disc#1 from SOURCE Tower to DESTINATION Tower
```

#### Let us make it Two
Still it is not much to worry about. We can simply move the smallest disc to the VIA tower and bigger one to DESTINATION, and then took the smallestone from VIA tower and put that above biggerone in DESTINATION tower.
```
    Move Disc#1 from SOURCE Tower to VIA Tower
    Move Disc#2 from SOURCE Tower to DESTINATION Tower
    Move Disc#1 from VIA Tower to DESTINATION Tower
```

#### If there was Three
Now the problem is little bit harder than the previous. We cannot simply bring the smallest one from the top of SOURCE tower and put that in DESTINATION tower, because this will violate the rule. Then how could we solve it? Wait a minute, we have VIA tower in our hand right! So we can simply put the smallest one in DESTINATION tower and put the middle one in VIA tower and again bring the smallest one from DESTINATION tower and put that into VIA tower. So we can succesfuly put two of them in VIA tower without violating the rule. Now simply put the largest in DESTINATION tower and retrieve other two from VIA tower using SOURCE tower as temporary storage.
```
    Move Disc#1 from SOURCE Tower to DESTINATION Tower
    Move Disc#2 from SOURCE Tower to VIA Tower
    Move Disc#1 from DESTINATION Tower to VIA Tower
    Move Disc#3 from SOURCE Tower to DESTINATION Tower
    Move Disc#1 from VIA Tower to SOURCE Tower
    Move Disc#2 from VIA Tower to DESTINATION Tower
    Move Disc#1 from SOURCE Tower to DESTINATION Tower
```

### Solution of the Problem
So now you got the idea! In case of **N disc**, we will move **(N-1) disc** from SOURCE tower to the VIA tower and then put the **N<sup>th</sup>** one in the DESTINATION tower and put the rest from VIA tower upon it. But since we can move one disc at a time, we will perform the operation recursively. In that case, SOURCE tower will be used as temporary storage while moving disc from VIA tower to DESTINATION tower or vice-versa.
The algorithm so formed will be like this:
```
    Tower_of_Hanoi(N, SOURCE, DESTINATION, VIA)
        if N is 1
            then Move Disc#1 from SOURCE to DESTINATION
        else
            Tower_of_Hanoi(N - 1, SOURCE, VIA, DESTINATION)
            Move Disc#1 from SOURCE to DESTINATION
            Tower_of_Hanoi(N - 1, VIA, DESTINATION, SOURCE)
```

### How to Contribute
If you find the solution incorrect or incomplete or can be modified to betterment, register an issue in the `ISSUE` tab and a `PULL REQUEST` for edited version against `ISSUE_NO`. The `PULL REQUEST` must be in the following format:
```
shortlog: commit title

commit description

fixes: #issue_no
```
You can also contribute by adding solution to the problem in different **Programming Languages**