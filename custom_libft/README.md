# Libft 1337 Documentation

A documentation that explains libft functions

## I - ‘is’ functions:

### 1-isdigit:

```jsx
int	ft_isdigit(int c);
if char is between '0' and '9' return 1 ,else return 0 
```

### 2-isalpha:

```jsx
int	ft_isalpha(int c);
if char is between 'a' and 'z' or between 'A' or 'Z' return 1 ,else return 0
```

### 3-isalnum:

```jsx
int	ft_isalnum(int c);
if char is ft_isdigit or ft_isalpha return 1 , else return 0
```

### 4-isascii:

```jsx
int	ft_isascii(int c);
ascii characters are between 0 and 127 so is the char is between 0 and 127 
the function returns 1 else it return 0;
note : int-->0 != '0'<---char
```

### 5-isprint:

```jsx
int	ft_isprint(int c);
printable characters are between 32 /' '<--space and 126 / '~' 
(127 is not printable) so if c if between 32 and 126 function returns 1
else it returns 0
```

### —>Knowledge needed : ascii and chars

## II - ‘to’ functions:

### 1-tolower:

```jsx
int	ft_tolower(int c)
if number between 'A' and 'Z' add 32 to the char to make it lower and return it
else return the given char with no modification
```

### 2-toupper:

```jsx
int	ft_toupper(int c)
if number between 'a' and 'z' substract 32 to the char to make it upper 
and return it
else return the given char with no modification
```

### 3-atoi:

```jsx
int	ft_atoi(const char *str);

1- create a counter i and increment the string if str[i] is a space by creating
the static function is space ,spaces are ' ' '\n' '\t' '\v' '\f' '\r'
while (ft_isspace(str[i]))
		i++;

str['\n'][-][1][2][3][a]['\0']
					^
					i
2- if their is a sign '+' or '-' increment i to go to the first digit of the 
number but if it's a negative number multiply sign int variable by -1
if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}

str['\n'][-][1][2][3][a]['\0']
					   ^
					   i
3- create a finale loop that goes to each character that is a number substract 
from it '0' to turn it to a number and add it to a result variable then in 
the next loop multiply the previous value by 10 and add a new number again 
until their str[i] is no longer a number (we can use ft_isdigit() function)
while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
str['\n'][-][1][2][3][a]['\0']
					   ^
					   i
result = 1;
str['\n'][-][1][2][3][a]['\0']
							  ^
							  i
result = 1*10 + 2 =12;
str['\n'][-][1][2][3][a]['\0']
							     ^
							     i
result = 12*10 + 3 =123;
4- if multiply the number by the sign variable in case the number is signed
return (sign * result);
result = -123
```

### 4-itoa:

```jsx
char	*ft_itoa(int n);
example =-1234

1-create a long long variable number and asing n to it (to handle the smallest 
value in int max = 2147483647 / min = -2147483648 )+(we do this because
when we want to create the string we add the % number to the char number '0' 
so the %number has to be positive)

long long	nbr;
nbr = n;

2-caculate the lenth of the final string using a function 
static int	number_len(long long n);
2-1-we handle the case when the case when the numbr is == to 0 since we won't be 
able to handle in the counting loop
if (n == 0)
		return (1);
2-2-handle the situation if their is a negative number we increment the counter to
leave a space to '-'
if (n < 0)
	{
		n = n * -1;
		count++;
	}
nbr =-1234 *-1 = 1234 , count = 1; 
2-3-we count each digit by dividing it by 10 until it equals 0
while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
nbr = 1234 / 10 =123 , count=2;
nbr = 123 / 10 =12 , count=3;
nbr = 12 / 10 =1 , count=4;
nbr = 1 / 10 =0 , count=5;

3-we ft_calloc the count + 1 for the '\0' ft_calloc inisalizes everything to '\0'
if result ==NULL return NULL /(void*)0
str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);

str['\0']['\0']['\0']['\0']['\0']['\0']
4-if the number is 0 we put '0' in the first element the second element already
has '\0' so we return the string after this
if (nbr == 0)
	{
		str[0] = '0';
		return (str);
	}
5-if the number is negative we fill the first element of the string with '-'
and we multiply it by -1
if (nbr < 0)
	{
		str[0] = '-';
		nbr = nbr * -1;
	}
str['-']['\0']['\0']['\0']['\0']['\0']
6-we use a final function to fill the array
static char	*filling_array(char *str, int len, long long nbr)
we create a loop in whitch we modulo by 10 the number add it to '0' and divide by
10 the hole number to go to the next modulo we do this until we reach 0
we use the len to asign characters we go from the back to not be forced to handle
the '-' char if the nbr is negative (we len-- to skip the '\0')

while (nbr > 0)
	{
		len--;
		str[len] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (str);

str['-']['\0']['\0']['\0']['4']['\0']
														^
														len
1234 % 10 = 4, 4 + '0' ='4',nbr = 1234 /10 = 123
str['-']['\0']['\0']['3']['4']['\0']
											^
											len
123 % 10 = 3, 3 + '0' ='3',nbr = 123 /10 = 12
str['-']['\0']['2']['3']['4']['\0']
								^
							 len
12 % 10 = 2, 2 + '0' ='2',nbr = 12 /10 = 1
str['-']['1']['2']['3']['4']['\0']
					^
					len
1 % 10 = 1, 1 + '0' ='1',nbr = 1 /10 = 0

-return the filled string from itoa function
return (filling_array(str, len, nbr));
----------------
In summary : 1-count number of cararcters with handling if number is 0 or negative
						 2- allocate the space with ft_calloc with len +1 for '\0'
						 3-asign '0' to array if nbr == 0 and '-' if nbr <0
             4-fill the string and return it
```

### —>Knowledge needed : ascii and strings and chars and ints and longs with their max and min values and overflow

## III - ‘mem’ functions:

### 1-memset:

```c
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*var;
	unsigned char	byte;
	size_t			i;

	i = 0;
	byte = (unsigned char)c;
	var = (unsigned char *)b;
	while (i < len)
	{
		var[i] = byte;
		i++;
	}
	return (b);
}
-the smallest type c can handle is bytes
-we give it a void pointer and the size of the memory it points to and we ask it to
set each byte of the memory to the byte we gave to her (int c in this case) 
we do not care if the memory is int,char or float we only copy bytes and it may 
even point to an array that we give the size
-we have to cast c to "unsigned char" and b to "unsigned char*" because unsigned 
char is the equivalent to a byte (we dont use char because a byte is unsiged)
-we go throught each byte of the memory and asign the casted int to it
-we return the fully seted function in the end
```

### 2-bzero:

```c
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
-set all bytes to 0 lol
```

### 3-memchr:

```c
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*src;
	unsigned char	byte;	

	src = (unsigned char *)s;
	byte = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (src[i] == byte)
			return (&src[i]);
		i++;
	}
	return (NULL);
}
-looks for a byte in a memory space that we have it lenth
-we cast pointer and c like in memset
-we use a counter from 0 to i (i not counted because array starts with 0)
-if we find the byte we return its adress
-else we return NULL (not found)
```

### 4-memcmp:

```c
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*src1;
	unsigned char	*src2;

	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	if (!n)
		return (0);
	i = 0;
	while (i < n)
	{
		if (src1[i] != src2[i])
			return (src1[i] - src2[i]);
		i++;
	}
	return (0);
}
-compares tow blocks of memory byte by byte if their is a difference return the 
diferrence between the different values else return NULl/0
-we cast pointer and c like in memset
-we go throuht the function like in memchr
```

### 5-memcopy:

```c
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (!dst && !src)
		return (0);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
-copies a memory space in a memory space whithout carring about overlap
-we start with a stupid condition that no one knows why it's here
-we assign pointer to unsigned char like in previous functions
-we go througt the memory and asing each byte to the destination*
-we return the destination
```

### 6-memmove:

```c
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (d > s)
	{
		while (len)
		{
			len--;
			d[len] = s[len];
		}
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
-like memcopy but it handels overlap
-src and dest shares same memory space
-if dst is before destination iverlapping in this case is handled by memcopy
------>
dest ['a']['b']['c']['d']['e']['f']
						src['c']['d']['e']['f']
------>
dest ['c']['b']['c']['d']['e']['f']
						src['c']['d']['e']['f']
			 ^
-> we have no loss of data here
-if src is before destination going from left to right like memcopy
 may overwrite data
------>
src ['a']['b']['c']['d']['e']['f']
					dest['c']['d']['e']['f']
------>
src ['a']['b']['a']['d']['e']['f']
					dest['a']['d']['e']['f']
-> we lost data here in this case we no longer have 'c'
<-------
src ['a']['b']['c']['d']['e']['f']
					dest['c']['d']['e']['f']
<-------
src ['a']['b']['c']['d']['e']['d']
					dest['c']['d']['e']['d']
															 ^
<-------
src ['a']['b']['c']['d']['c']['d']
					dest['c']['d']['c']['d']
													^
-> we didnt lose the 'c' character like the first time
-to go from right to left we take the len and we decremate it in loop to go from 
the end to the start
-we return the dest like in memcpy in the end
```

### —>Knowledge needed : to know how c language manages memory

## IV - standard library strings functions:

### 1-strlen:

```c
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
-is there any thing to explain in this fucking function ?
-it counts number of chars in a string but doesnt count the '\0'
```

### 2-strchr:

```c
char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
-we give to this function a char to search for it in a stringif it finds it, 
it returns the adress of this char in this string if not it returns 0.
-in this function we go from the begining to the end and we include the '\0'
in the research this is why we used ft_strlen function
-we cast the c to char because it's an int and we cast the adress bcause it
points to a const char not to a char
----> const char *p != char *const p
```

### 3-strrchr:

```c
char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return ((char *)&s[len]);
		len--;
	}
	return (0);
}
-same behaviour as strch() just it starts searching from the end to the begining
```

### 4-strncmp:

```c
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (!s1[i] && !s2[i])
			return (0);
		i++;
	}
	return (0);
}
-goes from 0 to n-1 and compaires each char of the string if their is a difference
it returns the difference between the tow chars in unsigned char value 
probably for extended ascii or because we don't want negative result
-if the both strings end at the same time before the given size we return 0 
because they are not different 
-we didn't include the condition if (!s1[i] && !s2[i]) in the while loop in (fact
it's it oposite (s1[i] || s2[i]) )because we wanted to not enter the loop if n
was equal to 0 , we can include this condition in the while loop if we want
we just have to add a condition if n was equal to 0
```

### 5-strnstr:

```c
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;

	if (little[0] == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	i = 0;
	while (big[i] && i + ft_strlen(little) <= len)
	{
		if (big[i] == little[0])
		{
			if (ft_strncmp(&big[i], little, ft_strlen(little)) == 0)
			{
				return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (0);
}
-the function takes a little string and sreaches for it in a bigger string
it returns the adress of the first char of the found sting in the big string
else it returns NULL all this in a limited lenth len
-we go throught each element of big until big ends and if the first char 
corspands the first char of litle we compaire the strings until the lenth of
litle if the compairison is a success we return the adress of the first 
char of the string else we go to the next char if nothing is found 
we return NULL
-we added the condition in the loop (i + ft_strlen(little) <= len) because the
little string may be in the big string but a part of it is under the len and part
of it higher than len so we need to limit the research to the given len

len = 3
big[a][b][c][d][e][\0]
small[c][d][e]
-> the function should return null here
```

### 6-strlcpy:

```jsx
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dstsize)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
-copies a string into an other string adding automaticly \0 ,the \0 is part of the 
specified lenth 
- if the lenth is 0 we return the lenth of the src 
- we start coping until we reach destsize -1 to leave a place to the \0 and we 
return lenth of src
```

### 7-strlcat:

```jsx
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	if (dst == NULL && dstsize == 0)
		return (0);
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	i = 0;
	j = dst_len;
	while (src[i] && j < dstsize - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = 0;
	return (src_len + dst_len);
}
-concatenates a string into an other string in a specified lenth defined as 
a parameter , this lenth is the lenth of dest + lenth of src + 1 for \0
- if dst is NULL and size specified is 0 we return 0 because we copy nothing
in an empty space we return 0 that is the value of the given lenth ,this is 
the only case handled by this function don't ask my why
- if the given lenth is higher than the lenth of the destination we return 
the given lenth  + the lenth of the source don't ask me why we do this the 
guy who made this function is a mad man 
- we go throught a loop adding the src in the dst starting from the \0 of the
src
-we add \0 at the end and we return the lenth of src + lenth of dest , we 
probably do this when we can call this function just to know the total size to 
allocate then we allocate after that we copy src in allocated space and then 
finally we concatenate 
-in general we return the lenth of src + the smaller value between the given 
lenth and lenth of dst
```

### —>Knowledge needed : to know how strings work and how chars work in strings

### 8-calloc:

```jsx
void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	if (count >= 18446744073709551615UL || size >= 18446744073709551615UL)
		return (NULL);
	str = malloc(count * size);
	if (!str)
		return (0);
	ft_bzero(str, count * size);
	return (str);
}
- we allocate the count multiplied by the size and initialize evrything with 0
then we return the allocated space
-(count >= 18446744073709551615UL || size >= 18446744073709551615UL) for 
overflow
```

### 9-strdup:

```jsx
char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*duplicate;

	len = ft_strlen(s1) + 1;
	duplicate = (char *)ft_calloc(len, sizeof(char));
	if (!duplicate)
		return (0);
	ft_strlcpy(duplicate, s1, len + 1);
	return (duplicate);
}
- we duplicate a string , we first calculate it lenth we calloc with lenth +1 
for the \0 ,check if no space is allocated and copy evrything in the new string 
```

### —>Knowledge needed : to know about strings and memory allocation

## V - string functions in part 2:

### 1-substr:

```jsx
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (s == NULL)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		return ((char *)ft_calloc(1, sizeof(char)));
	res = (char *)ft_calloc(sizeof(char), len + 1);
	if (!res)
		return (0);
	ft_strlcpy(res, &s[start], len + 1);
	return (res);
}
-creates a small string from a big string starting from an index and ending in
a lenth 
-if s is null return NULL for protection
-if len > lenth -start it means that we will malloc a space higher than the
requied space like if we give to the function 500000 and the string has only 5
500000 space in memory will be allocated for nothing
-if the start is higher or equal than the to the lenth of the string this means
that the string has already ended before the start in this case we allocate 
an empty string aka a char with \0
-if everything went good we allocate the lenth + 1 for the \0 and we copy 
whith strlcpy from the adress of the start with len + 1 for \0 
-finally we return the result allocated  
```

### 2-strjoin:

```jsx
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (0);
	len = ft_strlen(s1);
	len += ft_strlen((s2));
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (0);
	ft_strlcpy(result, s1, len + 1);
	ft_strlcat(result, s2, len + 1);
	return (result);
}
- we join tow string in one allocated string 
- s1 == NULL || s2 == NULL for memory protectiom from segfault
- we calculate the lenth of both strings and allocate this string +1 for the \0 
- we lcopy the first and lcat the second and return the result
```

### 3-strtrim:

```jsx
char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	if (s1 == NULL || set == NULL)
		return (0);
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	if (s1[i] == '\0')
		return ((char *)ft_calloc(sizeof(char), 1));
	while (ft_strchr(set, s1[j]))
		j--;
	return (ft_substr(s1, i, (j - i + 1)));
}

s[-][/][-][-][h][e][l][l][o][/][-][-][\0]
set[-][/]
---->s[h][e][l][l][o][\0]

-trims the bigenning and the end a string a char that is part of a set
- s1 == NULL || s2 == NULL for memory protectiom from segfault
-we loop from the begining and look if the the character is in the set by 
searching for it in this set with strchr() if it is found we continue the 
loop and we end the loop until nothing is found or the sting has ended 
the s1[i] is used in case we trim with \0
-if we reach the end in other trems the string is made only of the characters 
to trim we return an empty string 
-we loop from the ending looking if their is any character like in the first 
loop 
-finally we create the string by giving to substring the address of the start of 
the trimed string and the lenth by substracting j - i + 1 (+1 because for the 
lenth we need to add 1) and we return the value of the substring
```

### 4-split:

```jsx

static int	c_count(char const *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	**free_all(char **big, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(big[i]);
		i++;
	}
	free(big);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**big;
	int		i;
	int		j;

	if (!s)
		return (0);
	count = c_count(s, c);
	big = (char **)ft_calloc(count + 1, sizeof(char *));
	if (!big)
		return (0);
	j = 0;
	i = 0;
	while (j < count)
	{
		s = s + i;
		while (*s == c)
			s++;
		i = ft_strchr(s, c) - s;
		big[j] = ft_substr(s, 0, i);
		if (!big[j])
			return (free_all(big, j));
		j++;
	}
	return (big);
}
-fucking split splits a big string into a lot of small strings stored into an 
array of pointers the split is with a char to split from the beggining 
the midle and the end
- !s to protect the function
-c_count counts the number of strings in the big string

static int	c_count(char const *str, char c)
-> we loop in the string if we find a corespanding char we increment until we 
do no longer find a correspandence in this case we increment the string counter 
and we go throught a string that goes throught the found string we add the 
condition s[i] in this loop in case the string ended and doesn't 
have the character c at the end , when we end this loop the bigger loop restarts
and we count with it the number of strings
-after counting all the strings we malloc the count + 1 for the final NULL 
pointer 
-if count is 0 we malloc a pointer with NULL value the loop won't start and 
we return this allocated pointer
-the loop will start with s increment it with i for later , a loop will go
throught each string to increment s if found a corspendence with c ,

[-][-][h][e][-][l][l][-][o][-][\0]
			 ^
			 s
-here we use strchr to find to us the first c char that we split with
[-][-][h][e][-][l][l][-][o][-][\0]
			 ^     ^
			 s    strch(s,c)
-we substract s value from strch() value and now we have the lenth of the string
to split
-whith substr() we create the substring to be splited and we asign it to big[j]
- if we have a problem in the alloction of the string we use the function 
free_all() to free all previous strings and the big string
- we increment s with i to go to the next c delemeter
[-][-][h][e][-][l][l][-][o][-][\0]
						 ^
						 s
we continue like this until the string ends and we will have a fully splited 
string 

[0] -> [h][e][\0]
[1] -> [l][l][\0]
[2] -> [o][\0]
[3] -> NULL
```

### —>Knowledge needed : to know about malloc , strings , pointer to pointer and 2d allocated array

## VI - pointer to functions in part 2:

### 1-striteri:

```jsx
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
-function that goes throught a string and applies a function that we pointed to 
it in the parameters of the function 
- s == NULL || f == NULL for protection
- we loop , apply the function to the adress of the char of the string, we give 
to it the index too ,why? i don't know
```

### 2-strmapi:

```jsx
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	if (!s || !f)
		return (0);
	res = ft_strdup(s);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	return (res);
}
- duplicates a string and asignes to each element of the new string a modified 
version of the corespanding char in the original srtring this modification
is done with the function that is pointed as an argument ,we give it the index
of the char that we are in in the loop why ? i don't know   
- (!s || !f) for protection  
- we return the new string 'res' 
```

### —>Knowledge needed : to know about pointer to functions

## VI - putfunctions in part 2:

### 1-putchar_fd:

```jsx
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
- prints a char in a difined file discriptor we give to it the adress of the 
char and 1 because we want to write 1 char 
```

### 2-putstr_fd:

```jsx
void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
}
- we protect the fuction from NULL 
- we write in the file descriptor the string ,we give it the adress of the first 
element of the string , we give it the size of the string without the \0 and it
writes the string in the given file descriptor 
```

### 3-putendl_fd:

```jsx
void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
-prints to us the string + \n in the given file decriptor
```

### 4-putnbr_fd:

```jsx
void	ft_putnbr_fd(int n, int fd)
{
	long	i;

	i = n;
	if (i < 0)
	{
		ft_putchar_fd('-', fd);
		i = i * -1;
	}
	if (i > 9)
		ft_putnbr_fd(i / 10, fd);
	ft_putchar_fd(i % 10 + '0', fd);
}

- puts each digit of an int in form of a char in the given file descriptor
prints the '-' of the number if the number is negative 
- we use long to handel the min value of int when we multiply it by -1
1- if number is negative we multiply it by -1 and put the '-' character in 
given file decriptor 
->now we have just an unsigned number to print each of its digits
2- we call the fuction recurcivly until we reach a number lower than 9 
then we put the given number + '0' because it's a char

->123456
->12345 -> putchar(6+'0')  ^
->1234 -> putchar(5+'0')   |
->123 -> putchar(4+'0')    |
->12 -> putchar(3+'0')     |
->1 -> putchar(2+'0')      |
->putchar(1+'0')           |
we will call the function recursivly many times when the number will be lower 
than 10 after that the function returns back to print the each number from the
left to the right with the %10 plus the '0' and we put each digit in the order
of the original number 
```

### —>Knowledge needed : to know write function , file descriptor , recursion, int max and min value (open function maybe)

## VII - bonus linked list

### 1-ft_lstnew:

```jsx
t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *)ft_calloc(1, sizeof(t_list));
	if (!lst)
		return (0);
	lst->content = content;
	return (lst);
}
-mallocs a list and puts the content in it
```

### 2-ft_lstadd_front:

```jsx
void	ft_lstadd_front(t_list **lst, t_list *n)
{
	t_list	*tmp;

	if (!lst || !n)
		return ;
	tmp = *lst;
	*lst = n;
	n -> next = tmp;
}
-if pointer is empty and node is empty return 
-else save the adress of the node in a temporary pointer
-give add the node to the list and make it point to the first node 
```

### 3-ft_lstsize:

```jsx
int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{	
		lst = lst->next;
		i++;
	}
	return (i);
}
- goes to a list and counts each elememt until it reaches NULL
```

### 4-ft_lstlast:

```jsx
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}
-goes into a loop and goes throught each node to it next if it is NULL to 
save the adress of the node then we return NULL
```

### 5-ft_lstadd_back:

```jsx
void	ft_lstadd_back(t_list **lst, t_list *n)
{
	t_list	*tmp;

	if (!lst || !n)
		return ;
	if (!*lst)
	{
		*lst = n;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp -> next = n;
}
- adds a node at the back 
-if lst is empty just add the node
-if not we go to the last element of the node and asign to it
```

### 6-ft_lstdelone:

```jsx
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst -> content);
	free(lst);
}
- deletes the content of the list then free the list
- if (!lst || !del) to protect the function
```

### 7-ft_lstclear:

```jsx
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*v;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	tmp = *lst;
	v = *lst;
	while (*lst != NULL )
	{
		v = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = v;
	}
	tmp = NULL;
}
-if (!lst || !del) to protect function
- v is a tmporary variable we go throught a loop we save the value of the
next node ,then we delete the one we are in and after that we asign to the 
list the saved version
at the end we set the original pointer to NULL just as an initialisation
```

### 8-ft_lstiter

```jsx
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}
we go throught the list and apply to each node the given function
```

### 9-ft_lstmap

```jsx
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dup;
	t_list	*node;

	if (!lst || !f || !del)
		return (0);
	dup = NULL;
	while (lst != NULL)
	{
		node = ft_lstnew(f(lst -> content));
		if (node == NULL)
		{
			ft_lstclear(&dup, del);
			return (0);
		}
		ft_lstadd_back(&dup, node);
		lst = lst -> next;
	}
	return (dup);
}
- we create a dup pointer that points to the hole new function we initialize it 
whith NULL because we will use the addback() function for the first node 
- we create a new node in node pointer each time with lsnew that has a modified 
version of the content of the list we add back the new node to the dup pointer 
and go to the next node to allocate the next node 
- if their is a problem in the process the entire list is freed with lstclear
-at the end we return the complete list
```

### —>Knowledge needed :  structures and linked lists, malloc & free , pointer to function

```
void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	if (count >= 18446744073709551615UL || size >= 18446744073709551615UL)
		return (NULL);
	str = malloc(count * size);
	if (!str)
		return (0);
	ft_bzero(str, count * size);
	return (str);
}
```

## VIII -Makefile and header

 

```jsx
for headerfile just put the prototypes and the structs
for Makefile don't use wildcards just like this 

NAME = libft.a
CC = gcc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror -I .
RM = rm -rf
HEADER  = libft.h

SRC = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \

BSRC = ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c \

OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

all: $(NAME)

bonus: all $(BOBJ)
	@$(AR) $(NAME) $(BOBJ)

$(NAME):$(OBJ)
	@$(AR) $@ $^

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< 

clean:
	@$(RM) $(OBJ) $(BOBJ)
fclean: clean
	@$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re bonus

```