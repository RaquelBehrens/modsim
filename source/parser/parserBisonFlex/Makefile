all: parser lexer

parser:
#       sudo apt-get install xsltproc (para visualizar o xml do parser)
# 	-Wcounterexamples --update
#	bison --update --graph=bisongraph.dot --locations --verbose --xml=bisonreport.xml --defines=../GenesysParser.h -o ../GenesysParser.cpp bisonparser.yy
	#--report=all -rcex --report-file=bisonparser.report \
	bison --locations --debug --feature=caret \
	-Wall \
	--xml=bisonparser.xml \
	--defines=../GenesysParser.h \
	--verbose --output ../GenesysParser.cpp \
	--graph=bisonparser.dot \
	bisonparser.yy 

lexer:
#	flex --debug --full -o ../Genesys++-scanner.cpp lexerparser.ll
	flex --full -o ../Genesys++-scanner.cpp lexerparser.ll
