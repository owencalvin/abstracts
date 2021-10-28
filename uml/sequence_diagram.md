# Diagramme avec plusieurs participants

```mermaid
sequenceDiagram
  participant Guest
  participant Server
  participant Owen

  loop Until correct
    alt Wrong log infos
        Guest->>Server: Wring log infos for the owen user
        Server->>Guest: Unauthorized: wrong email or password
    else Correct infos
      Guest->>Server: Login as owen with email and passcode
      Server->>Guest: Authorized
      Owen->>Server: Get owen's homepage
      Server->>Owen: owen's homepage sent
    end
  end
```

# Attention
Ces deux diagrammes se lisent de façon bien différente, dans le premier diagramme l'utilisateur fait dans l'ordre:
1. Demande la page de owen et reçoit systématiquement une erreur
2. Se trompe à chaque fois qu'il se connecte
3. Arrive à se connecter

Alors que dans le deuxième **l'utilisateur fait soit le cas 1, le cas 2 ou le cas 3**.

> Les diagrammes suivants n'ont pas de sens, c'est juste pour savoir comment les lire

```mermaid
sequenceDiagram
  participant Guest
  participant Server
  participant Owen

  alt Unauthed
    Guest->>Server: Get owen's homepage
    Server->>Guest: Unauthorized
  end

  loop Until correct
    alt Wrong log infos
      Guest->>Server: Wring log infos for the owen user
      Server->>Guest: Unauthorized: wrong email or password
    end
  end

  alt Correct infos
    Guest->>Server: Login as owen with email and passcode
    Server->>Guest: Authorized
    Owen->>Server: Get owen's homepage
    Server->>Owen: owen's homepage sent
  end
```

```mermaid
sequenceDiagram
  participant Guest
  participant Server
  participant Owen

  alt Unauthed
    Guest->>Server: Get owen's homepage
    Server->>Guest: Unauthorized
  else Wrong log infos
    Guest->>Server: Wrong log infos for the owen user
    Server->>Guest: Unauthorized: wrong email or password
  else Correct infos
    Guest->>Server: Login as owen with email and passcode
    Server->>Guest: Authorized
    Owen->>Server: Get owen's homepage
    Server->>Owen: owen's homepage sent
  end
```
