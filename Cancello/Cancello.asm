asm Cancello

import StandardLibrary


signature:

	//DOMINI
	enum domain GateStatus = {OPENING | STOPOPEN |CLOSING | STOPCLOSED}

	enum domain SecurityGuard = {ON | OFF}
	enum domain Pulsanti = {OPEN | CLOSE | NOTHING }

	
	
	//CONTROLLED
	dynamic controlled gate : GateStatus
	

	dynamic controlled autoClosetime : Integer
	dynamic controlled state : String
	
	//MONITORED
	dynamic monitored telecomandoAction: Pulsanti
	dynamic monitored guard : SecurityGuard 
	
	static closeTime : Integer
definitions:
	
	function closeTime = 2

	rule r_emergencyOpen =
		if(gate=CLOSING and guard=ON) then 
			seq
			gate := OPENING 
			state:="emergency open!"
			endseq
		endif 
	
	rule r_close =
		if (gate=OPENING or gate=STOPOPEN) then 
			seq
			gate:=CLOSING
			state:="closing gate"
			endseq
		endif
	rule r_open =
		if (gate=CLOSING or gate=STOPCLOSED) then 
			seq
				gate:=OPENING
				state:="opening gate"
			endseq
		endif
	
	
	rule r_stop =
		seq
			if(gate=OPENING) then 
				seq
				gate:= STOPOPEN
				autoClosetime := closeTime
				state:="Gate stopped open"
				endseq
			endif
			if (gate=CLOSING and guard=OFF) then
				seq
				gate:= STOPCLOSED
				state:="Gate stopped closed"
				endseq
			endif
			if (gate=STOPOPEN and autoClosetime=0) then r_close[]
			endif
		endseq
	
	rule r_countDown=
		if (autoClosetime>0) then autoClosetime := autoClosetime - 1
		endif
	
	
	rule r_autoClose =
		if( gate=STOPOPEN ) then 
			par
			r_countDown[]
			state := "counting down"
			endpar
		endif

	
	
main rule r_Main =  
		if (telecomandoAction = OPEN ) then	r_open[]
		
		else if (telecomandoAction = CLOSE) then
			par
				r_close[]
				r_emergencyOpen[]
			endpar
		else if (telecomandoAction = NOTHING) then
			seq
			r_autoClose[]
			r_stop[]
			r_emergencyOpen[]
			endseq
		endif endif endif
		
default init s0:
	function guard = OFF
	function gate=STOPCLOSED
