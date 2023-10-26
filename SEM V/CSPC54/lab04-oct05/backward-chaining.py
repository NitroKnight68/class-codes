#  Backward chaining
class Rule:
    def __init__(self, consequent, antecedent):
        self.consequent = consequent  # The fact to be derived
        self.antecedent = antecedent  # List of antecedent conditions (facts)

class Fact:
    def __init__(self, name, value=False):
        self.name = name  # Fact name
        self.value = value  # Fact value (True or False)

class KnowledgeBase:
    def __init__(self):
        self.rules = []  # List of rules
        self.facts = {}  # Dictionary to store facts and their values

    def add_rule(self, consequent, antecedent):
        rule = Rule(consequent, antecedent)
        self.rules.append(rule)

    def add_fact(self, name, value=False):
        fact = Fact(name, value)
        self.facts[name] = fact

    def evaluate_hypothesis(self, goal):
        if self.backward_chain(goal):
            print(f"The hypothesis '{goal}' is True.")
        else:
            print(f"The hypothesis '{goal}' is False.")

    def backward_chain(self, goal):
        if goal in self.facts:
            return self.facts[goal].value

        for rule in self.rules:
            if rule.consequent == goal:
                antecedent_values = [self.backward_chain(antecedent) for antecedent in rule.antecedent]
                if all(antecedent_values):
                    self.facts[goal].value = True
                    return True
        return False

# Create a knowledge base
kb = KnowledgeBase()

# Define rules
kb.add_rule('Hypothesis', ['A'])
kb.add_rule('A', ['C', 'D'])
kb.add_rule('B', ['E'])
kb.add_rule('C', [])
kb.add_rule('D', [])
kb.add_rule('E', ['F'])
kb.add_rule('F', [])

# Add initial facts
kb.add_fact('C', False)
kb.add_fact('D', True)
kb.add_fact('A', False)
kb.add_fact('B', True)
kb.add_fact('E', False)
kb.add_fact('F', True)
kb.add_fact('Hypothesis', )

# Evaluate a hypothesis using backward chaining
kb.evaluate_hypothesis('Hypothesis')