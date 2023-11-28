%: %.md
	npx slidev --open "$^"

%.pdf: %.md
	npx slidev export "$^" --output "$@"

clean:
	rm *.pdf
