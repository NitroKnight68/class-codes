#Forward chaining
class Rule:
    def __init__(self, antecedent, consequent):
        self.antecedent = antecedent  # List of antecedent conditions
        self.consequent = consequent  # Consequent (result) of the rule


class Fact:
    def __init__(self, name, value=False):
        self.name = name  # Fact name
        self.value = value  # Fact value (True or False)


class KnowledgeBase:
    def __init__(self):
        self.rules = []  # List of rules
        self.facts = {}  # Dictionary to store facts and their values

    def add_rule(self, antecedent, consequent):
        rule = Rule(antecedent, consequent)
        self.rules.append(rule)

    def add_fact(self, name, value=False):
        fact = Fact(name, value)
        self.facts[name] = fact

    def evaluate_rules(self):
        while True:
            new_facts_derived = False

            for rule in self.rules:
                if self.apply_rule(rule):
                    new_facts_derived = True

            if not new_facts_derived:
                break

    def apply_rule(self, rule):
        antecedent_values = [self.facts[condition].value for condition in rule.antecedent]

        if all(antecedent_values) and not self.facts[rule.consequent].value:
            self.facts[rule.consequent].value = True
            print(f"Derived new fact: {rule.consequent}")
            return True

        return False

    def get_fact_value(self, name):
        return self.facts[name].value


# Create a knowledge base
kb = KnowledgeBase()

# Define rules
kb.add_rule(['B'], 'A')
kb.add_rule(['A', 'C'], 'E')
kb.add_rule(['D'], 'F')

# Add initial facts
kb.add_fact('B', True)
kb.add_fact('C', True)
kb.add_fact('D', False)
kb.add_fact('A', False)
kb.add_fact('E', False)
kb.add_fact('F', True)

# Evaluate the rules to derive new facts
kb.evaluate_rules()

# Check the value of a fact
print("Value of 'E':", kb.get_fact_value('D'))
print("Value of 'F':", kb.get_fact_value('F'))