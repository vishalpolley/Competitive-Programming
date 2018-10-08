def num_to_words(num):
    d = {
            0 : 'Zero', 1 : 'One', 2 : 'Two', 3 : 'Three', 4 : 'Four', 5 : 'Five',
            6 : 'Six', 7 : 'Seven', 8 : 'Eight', 9 : 'Nine', 10 : 'Ten',
            11 : 'Eleven', 12 : 'Twelve', 13 : 'Thirteen', 14 : 'Fourteen',
            15 : 'Fifteen', 16 : 'Sixteen', 17 : 'Seventeen', 18 : 'Eighteen',
            19 : 'Nineteen', 20 : 'Twenty', 30 : 'Thirty', 40 : 'Forty',
            50 : 'Fifty', 60 : 'Sixty', 70 : 'Seventy', 80 : 'Eighty', 90 : 'Ninety'
        }
    k = 1000
    m = k * 100

    if (num < 20):
        return d[num]

    if (num < 100):
        if num % 10 == 0: return d[num]
        else: return d[num // 10 * 10] + ' ' + d[num % 10]

    if (num < k):
        if num % 100 == 0: return d[num // 100] + ' Hundred'
        else: return d[num // 100] + ' Hundred ' + num_to_words(num % 100)

    if (num < m):
        if num % k == 0: return num_to_words(num // k) + ' Thousand'
        else: return num_to_words(num // k) + ' Thousand ' + num_to_words(num % k)

    if (num >= m):
        return 'Out of bounds'

if __name__ == "__main__":
    n1, n2 = map(int, input().split())
    if n1 < n2:
        c11, c12 = n1, n2
    else:
        c11, c12 = n2, n1
    if n1 == n2:
        print(n1)

    while c11 != c12:
        c21, c22 = num_to_words(c11), num_to_words(c12)
        if c21 < c22:
            c41, c42 = c11, c12
        else:
            c41, c42 = c12, c11

        c11 = c11 + c41
        c12 = c12 + c42

        if (c11 > 99999) or (c12 > 99999):
            print('Out of bounds')
            exit()

        if c11 == c12:
            print(c11)
            exit()


