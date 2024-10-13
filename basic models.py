import pandas as pd
from sklearn.feature_extraction.text import TfidfVectorizer
from xgboost import XGBClassifier
from sklearn.metrics import accuracy_score
from collections import Counter

# Load datasets
train_data = pd.read_csv('C:\\Users\\ANUSHKA SINGH\\Desktop\\cs771\\mini-project\\mini-project-1\\datasets\\train\\train_text_seq.csv')
valid_data = pd.read_csv('C:\\Users\\ANUSHKA SINGH\\Desktop\\cs771\\mini-project\\mini-project-1\\datasets\\valid\\valid_text_seq.csv')

# Extract input features and labels
X_train = train_data['input_str']
y_train = train_data['label']  # Assuming 'label' is the column containing the target variable
X_valid = valid_data['input_str']
y_valid = valid_data['label']

# Apply TF-IDF Vectorizer to convert the text data into numeric vectors
tfidf = TfidfVectorizer(max_features=1000)  # Limit to 1000 features (you can adjust based on your data)
X_train_tfidf = tfidf.fit_transform(X_train)
X_valid_tfidf = tfidf.transform(X_valid)

# Find the number of unique classes in the target
num_classes = len(set(y_train))

# Create the XGBoost model with L2 regularization and specify the number of classes
model = XGBClassifier(objective='multi:softmax',  # Use softmax for multiclass classification
                      num_class=num_classes,      # Set the number of unique classes
                      reg_lambda=1,               # L2 regularization strength
                      use_label_encoder=False,    # Avoid label encoding warnings
                      eval_metric='mlogloss',     # Evaluation metric
                      max_depth=6,                # Depth of the tree
                      n_estimators=100,           # Number of trees/boosting rounds
                      learning_rate=0.1)          # Learning rate for boosting

# Train the model
model.fit(X_train_tfidf, y_train)

# Predict on validation data
y_pred = model.predict(X_valid_tfidf)

# Calculate accuracy
accuracy = accuracy_score(y_valid, y_pred)
print(f"Accuracy: {accuracy}")
