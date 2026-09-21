Justificativa Técnica do Projeto



O circuito foi desenvolvido para representar, de forma simplificada, um sistema inteligente de gerenciamento de energia aplicado a um eletroposto para veículos elétricos. A solução utiliza entradas digitais para monitorar as condições do sistema e LEDs para indicar visualmente o estado de operação em tempo real.

Lógica de Operação do Hardware:



Os botões cumprem um papel fundamental na simulação, representando as duas principais condições de contorno consideradas pelo sistema:



Presença de um veículo conectado: Indica se há demanda ativa por energia.

Ocorrência de um horário de pico na rede elétrica: Sinaliza a necessidade de modulação e alívio da infraestrutura local.



A partir dessas entradas discretas, o microcontrolador executa uma lógica de controle via software que determina instantaneamente qual estado deve ser apresentado pelos sinalizadores visuais.



Feedback Visual e Tomada de Decisão: A utilização de diferentes LEDs permite representar claramente três situações críticas de operação urbana:

● Funcionamento Normal: Estação operando em potência máxima nominal.

● Situação de Atenção: Horário de pico detectado, exigindo redução preventiva de potência.

● Modo de Espera: Sistema alimentado e aguardando a conexão de um veículo elétrico.



Conceito Chave: O circuito demonstra na prática como informações e telemetrias coletadas do ambiente podem ser utilizadas para automatizar e auxiliar na tomada de decisões complexas relacionadas ao gerenciamento de eficiência energética.



Flexibilidade do Desenvolvimento com Arduino: A escolha da plataforma Arduino Uno como cérebro do protótipo facilita a implementação e a escalabilidade do projeto. Através dele, é possível programar e refinar a lógica de controle de forma ágil, permitindo alterar regras de negócio e condições de funcionamento via software, sem a necessidade de modificar fisicamente as conexões do circuito elétrico na bancada. Essa versatilidade torna a solução ideal para uma demonstração acadêmica robusta de automação, eficiência e controle energético inteligente.

