def main():
    n = int(input())
    arr = []
    dict = {}
    for i in range(n):
        arr.append(input())
        dict[hash(arr[i])] = arr[i]

    notypo = True

    for i in arr:
        #print("curr: " + i)
        for j in range(len(i)):
            s = i
            s = s.replace(i[j],'',1)
            #print(j)
            #print(s)
            if hash(s) in dict:
                print(i)
                notypo = False
                break
        if(hash(i[:-1]) in dict):
            print(i)
            notypo = False

    if notypo:
        print("NO TYPOS")


main()