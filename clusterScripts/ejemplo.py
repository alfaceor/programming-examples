def parrot(voltage, state='a stiff', action='voom', type='Norwegian Blue'):
	print "-- This parrot wouldn't", action,
	print "if you put", voltage, "volts through it."
	print "-- Lovely plumage, the", type
	print "-- It's", state, "!"
	
def cheeseshop(kind, *arguments, **keywords):
    print "-- Do you have any", kind, "?"
    print "-- I'm sorry, we're all out of", kind
    for arg in arguments: print arg
    print "-" * 40
    keys = keywords.keys()
    keys.sort()
    for kw in keys: print kw, ":", keywords[kw]

