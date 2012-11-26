import re

def solve():
	s = raw_input()
	if len(s) == 0:
		return False

	s = s.replace(',', ' , ')
	s = s.replace('...', ' ... ')

	ss = s.split()

	s = ""
	for t in ss:
		if t == ',':
			s += t + ' '
		else:
			s += ' ' + t

	ans = re.sub('[ ]+', ' ', s)

	ans = ans.replace('. 0', '.0')
	ans = ans.replace('. 1', '.1')
	ans = ans.replace('. 2', '.2')
	ans = ans.replace('. 3', '.3')
	ans = ans.replace('. 4', '.4')
	ans = ans.replace('. 5', '.5')
	ans = ans.replace('. 6', '.6')
	ans = ans.replace('. 7', '.7')
	ans = ans.replace('. 8', '.8')
	ans = ans.replace('. 9', '.9')
	print ans.strip()
	return True

solve()
