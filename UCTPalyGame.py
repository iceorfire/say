def UCTPlayGame():
	state = NimState(15)
	while (state.GetMove()!=[]):
		print str(state)
		if state.playerJustMoved==1:
			m=UCT(rootstate = state,itermax = 1000, verbose = False)
		else:
			m=UCT(rootstate = state, itermax = 100,verbose=False)
		print "Best Move: "+str(m) + "\n"
		state.DoMove(m)
	if state.GetResult(state.playerJustMoved)== 1.0:
		print