def f(st, num):
    sts = st.split()
    gram = []
    for i in range(len(sts) - num):
        gram.append(sts[i:i + num])
    return gram
print(f("I am an NLPer", 2))
print("Hello World")