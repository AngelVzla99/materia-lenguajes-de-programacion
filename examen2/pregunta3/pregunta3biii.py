def suspenso(ls):
	if len(ls)==1: yield ls[0]
	elif len(ls)>1:
		m = []
		for e in suspenso(ls[1:]):
			m.append(e)
			if len(m)%(len(ls)-1)==0:
				for lista in ins(ls[0], m):
					for elem in lista :
						yield elem 
				m = []
