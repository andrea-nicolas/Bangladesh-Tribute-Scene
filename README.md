ASSIGNMENT INSTRUCTIONS

**Topic : Bangladesh Tribute Scene (Using DDA, Bresenham, Midpoint Circle)**
 
**Objective:**  
Draw a complete 2D scene on a pixel grid using only:  
• DDA Line Algorithm  
• Bresenham Line Algorithm  
• Midpoint Circle Algorithm  
No built-in line/circle functions allowed (except putpixel(x,y) or equivalent). 
 
**Output Requirements (What to Draw)**
 
NOTE: Draw the Part A,B and C all together in a single window as a whole scenary. 
 
**Part A: Bangladesh Flag (Mandatory)**  
• Draw a rectangle flag frame (border) using Bresenham line.  
• Draw the red circle (sun) using Midpoint Circle.  
• Place the circle slightly left of center like the real Bangladesh flag.  
• Add a flagpole using DDA line. 
 
**Part B: Shaheed Minar (Mandatory)**
Construct a simplified Shaheed Minar using rectangles, lines, and circles. 
Minimum required structure: 
• Base platform: one wide rectangle 
• Five vertical pillars: the middle pillar must be the tallest, and the others should be shorter on both sides 
• Top arch/curve: create the arch using circles/arc points from the Midpoint Circle Algorithm 

Algorithm usage rules for Part B: 
• Pillar edges: Bresenham 
• Some decorative lines: DDA 
• Any circular/arch element: Midpoint Circle 
 
**Part C: Extra Elements (Choose any TWO)** 
Pick two from the list and draw them using the algorithms: 
1. Sun rays (short lines around the circle) → DDA 
2. Stars (use lines only) → Bresenham 
3. Road / footpath in front of Shaheed Minar → Bresenham 
4. Flowers (small circles + stem lines) → Circle + DDA 
5. Clouds (overlapping circles) → Midpoint Circle 
6. Birds (two small arcs made from circle points) → Midpoint Circle

**Strict Algorithm Rules:**
• Every straight edge must be drawn by either DDA or Bresenham (not both randomly—label it). 
• Every circle/arc must use Midpoint Circle. 
• Must implement all three algorithms at least once. 

**Report Must include:**
1. Source Code 
2. Screenshot of output 
3. A short report of one page including: 
  a. Which parts use DDA, which use Bresenham, which use Midpoint Circle 
  b. At least 3 sample point outputs from each algorithm run (first 5 plotted points is fine)
