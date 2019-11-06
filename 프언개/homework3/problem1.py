import random

def nounPhrase(articles, nouns):
    phrase = []
    for article in articles:
        for noun in nouns:
            phrase.append(article+" "+noun)

    return phrase

def verbPhrase(verbs, noun_phases, preposition_phrases):
    phrase = []
    for verb in verbs:
        for nounPhase in noun_phases:
            for preposition in preposition_phrases:
                phrase.append(verb+" "+nounPhase+" "+preposition)

    return phrase


def p_Phrase(prepositions, nounPharses):
    pharse = []
    for preposition in prepositions:
        for nounPhrase in nounPharses:
            pharse.append(preposition + " "+nounPhrase)

    return pharse

def sentence(sentence_number, noun_phrases,verb_phrases):
    phrase = []
    sentence_list = []
    for noun_phrase in noun_phrases:
        for verb_phrase in verb_phrases:
            phrase.append(noun_phrase+" "+verb_phrase)

    for i in range(sentence_number):
        sentence_list.append(random.choice(phrase))

    return sentence_list

articles=("A","THE")
nouns=("BOY","GIRL","BAT","BALL")
preposition = ("WITH","BY")
verbs = ("HIT","SAW","LIKED")

noun_phrases = nounPhrase(articles,nouns)
preposition_phrases = p_Phrase(preposition,noun_phrases)
verb_phrases = verbPhrase(verbs,noun_phrases,preposition_phrases)

sentence_number = int(input("Enter te number of sentence: "))
for sentence in sentence(sentence_number,noun_phrases,verb_phrases):
    print(sentence)
