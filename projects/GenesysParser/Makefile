all: parser lexer

parser:
#       sudo apt-get install xsltproc (para visualizar o xml do parser)
# 	-Wcounterexamples --update
#	bison --update --graph=bisongraph.dot --locations --verbose --xml=bisonreport.xml --defines=../GenesysParser.h -o ../GenesysParser.cpp bisonparser.yy
	#--report=all -rcex --report-file=bisonparser.report \
	bison --locations --debug  --feature=caret \
	-Wall \
	--verbose \
	--defines=../../source/parser/GenesysParser.h \
	--output=../../source/parser/GenesysParser.cpp \
	--xml=../../source/parser/parserBisonFlex/bisonparser.xml \
	--graph=../../source/parser/parserBisonFlex/bisonparser.dot \
	--report-file=../../source/parser/parserBisonFlex/bisonparser.report \
	../../source/parser/parserBisonFlex/bisonparser.yy 

lexer:
	flex --full -o \
	../../source/parser/Genesys++-scanner.cpp \
	../../source/parser/parserBisonFlex/lexerparser.ll

generateDynLib:
	