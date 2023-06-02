
from SetOperations import Set

def createSet():
    n=int(input("Enter number of Elements in set"))
    s = Set(n)  
    return s

choice = 0
print("Create Set A")
s1 = createSet()
print(str(s1))
while choice != 10:
    print("|-------------------|")
    print("| Menu              |")
    print("| 1.Add             |")
    print("| 2.Remove          |")
    print("| 3.Contains        |")
    print("| 4.Size            |")
    print("| 5.Intersection    |")
    print("| 6.Union           |")
    print("| 7.Difference      |")
    print("| 8.Subset          |")
    print("| 9.Proper Subset   |")
    print("| 10.Exit           |")
    print("|-------------------|")

    choice = int(input("Enter Choice"))

    if choice==1:
        e = int(input("Enter Number to Add"))
        s1.add(e)
        print(str(s1))

    elif choice==2:
        e = int(input("Enter Number to Remove"))
        s1.remove(e)
        print(str(s1))

    elif choice==3:
        e = int(input("Enter Number to Search"))
        if e in s1:
            print("Number Present in Set")
        else:
            print("Number is not Present in Set")

        print(str(s1))

    elif choice==4:
        print("Set Contains {} elements".format(len(s1)))

    elif choice==5:
        print("Create a Set B for doing Intersection Operation")
        s2 = createSet()
        s3 = s1.intersect(s2)
        print("Set A = "+str(s1))
        print("Set B = "+str(s2))
        print("Intersection = "+str(s3))

    elif choice==6:
        print("Create a Set B for doing Union Operation")
        s2 = createSet()
        s3 = s1.union(s2)
        print("Set A = "+str(s1))
        print("Set B = "+str(s2))
        print("Union = "+str(s3))

    elif choice==7:
        print("Create a Set B for calculating Set Difference")
        s2 = createSet()
        s3 = s1.difference(s2)
        print("Set A = "+str(s1))
        print("Set B = "+str(s2))
        print("Difference = "+str(s3))

    elif choice==8:
        print("Create a Set B for checking Subset or not")
        s2 = createSet()
        isSubset = s1.isSubsetOf(s2)
        print("Set A = "+str(s1))
        print("Set B = "+str(s2))
        if isSubset:
            print("Set B is the Subset of Set A")
        else:
            print("Set B is not a Subset of Set A")

    elif choice==9:
        print("Create a Set B for checking ProperSubset or not")
        s2 = createSet()
        isProperSubset = s1.isProperSubset(s2)
        print("Set A = "+str(s1))
        print("Set B = "+str(s2))
        if isProperSubset:
            print("Set B is the Proper Subset of Set A")
        else:
            print("Set B is not a Proper Subset of Set A")

    elif choice==10:
        break;

    elif choice<1 or choice>10:
        print("Please Enter Valid Choice")
            
            
        

        
            
        
        
        
    
