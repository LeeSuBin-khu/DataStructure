class Matrix:
    def __init__(self, x1, x2, x3, x4):
        self.m = [[x1, x2], [x3, x4]];
    
    def __add__(self, m1):
        self.AddM = Matrix(self.m[0][0]+m1.m[0][0], self.m[0][1]+m1.m[0][1] , self.m[1][0]+m1.m[1][0], self.m[1][1]+m1.m[1][1])
        return self.AddM

    def __sub__(self, m1):
        self.SubM = Matrix(self.m[0][0]-m1.m[0][0], self.m[0][1]-m1.m[0][1] , self.m[1][0]-m1.m[1][0], self.m[1][1]-m1.m[1][1])
        return self.SubM

    def __str__(self):
        self.list1 = list()
        for j in range(len(self.m[0])):
            for i in self.m[j]:
                self.list1.append(i)
        return '{} {}\n{} {}'.format(self.list1[0], self.list1[1], self.list1[2], self.list1[3])

m1 = Matrix(1, 2, 3, 4)
m2 = Matrix(5, 6, 7, 8)

m3 = m1+m2
m4 = m1-m2
print(m3)
print(m4)