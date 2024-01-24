#include "clogs.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <threads.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>

int adjectivesc = 0;
static const char* adjectives[] = { //<<<
	"Different", "Used", "Important", "Every", "Large", "Available", "Popular",
	"Able", "Basic", "Known", "Various", "Difficult", "Several", "United",
	"Historical", "Hot", "Useful", "Mental", "Scared", "Additional",
	"Emotional", "Old", "Political", "Similar", "Healthy", "Financial",
	"Medical", "Traditional", "Federal", "Entire", "Strong", "Actual",
	"Significant", "Successful", "Electrical", "Expensive", "Pregnant",
	"Intelligent", "Interesting", "Poor", "Happy", "Responsible", "Cute",
	"Helpful", "Recent", "Willing", "Nice", "Wonderful", "Impossible",
	"Serious", "Huge", "Rare", "Technical", "Typical", "Competitive",
	"Critical", "Electronic", "Immediate", "Aware", "Educational",
	"Environmental", "Global", "Legal", "Relevant", "Accurate", "Capable",
	"Dangerous", "Dramatic", "Efficient", "Powerful", "Foreign", "Hungry",
	"Practical", "Psychological", "Severe", "Suitable", "Numerous",
	"Sufficient", "Unusual", "Consistent", "Cultural", "Existing", "Famous",
	"Pure", "Afraid", "Obvious", "Careful", "Latter", "Unhappy", "Acceptable",
	"Aggressive", "Boring", "Distinct", "Eastern", "Logical", "Reasonable",
	"Strict", "Administrative", "Automatic", "Civil", "Former", "Massive",
	"Southern", "Unfair", "Visible", "Alive", "Angry", "Desperate", "Exciting",
	"Friendly", "Lucky", "Realistic", "Sorry", "Ugly", "Unlikely", "Anxious",
	"Comprehensive", "Curious", "Impressive", "Informal", "Inner", "Pleasant",
	"Sudden", "Terrible", "Unable", "Weak", "Wooden", "Asleep",
	"Confident", "Conscious", "Decent", "Embarrassed", "Guilty", "Lonely",
	"Mad", "Nervous", "Odd", "Remarkable", "Substantial", "Suspicious", "Tall",
	"Tiny", "More", "Some", "One", "All", "Many", "Most", "Other", "Such",
	"Even", "New", "Just", "Good", "Any", "Each", "Much", "Own", "Great",
	"Another", "Same", "Few", "Free", "Right", "Still", "Best", "Public",
	"Human", "Both", "Local", "Sure", "Better", "General", "Specific",
	"Enough", "Long", "Small", "Less", "High", "Certain", "Little", "Common",
	"Next", "Simple", "Hard", "Past", "Big", "Possible", "Particular", "Real",
	"Major", "Personal", "Current", "Left", "National", "Least", "Natural",
	"Physical", "Short", "Last", "Single", "Individual", "Main", "Potential",
	"Professional", "International", "Lower", "Open", "According",
	"Alternative", "Special", "Working", "True", "Whole", "Clear", "Dry",
	"Easy", "Cold", "Commercial", "Full", "Low", "Primary", "Worth",
	"Necessary", "Positive", "Present", "Close", "Creative", "Green", "Late",
	"Fit", "Glad", "Proper", "Complex", "Content", "Due", "Effective",
	"Middle", "Regular", "Fast", "Independent", "Original", "Wide",
	"Beautiful", "Complete", "Active", "Negative", "Safe", "Visual", "Wrong",
	"Ago", "Quick", "Ready", "Straight", "White", "Direct", "Excellent",
	"Extra", "Junior", "Pretty", "Unique", "Classic", "Final", "Overall",
	"Private", "Separate", "Western", "Alone", "Familiar", "Official",
	"Perfect", "Bright", "Broad", "Comfortable", "Flat", "Rich", "Warm",
	"Young", "Heavy", "Valuable", "Correct", "Leading", "Slow", "Clean",
	"Fresh", "Normal", "Secret", "Tough", "Brown", "Cheap", "Deep",
	"Objective", "Secure", "Thin", "Chemical", "Cool", "Extreme", "Exact",
	"Fair", "Fine", "Formal", "Opposite", "Remote", "Total", "Vast", "Lost",
	"Smooth", "Dark", "Double", "Equal", "Firm", "Frequent", "Internal",
	"Sensitive", "Constant", "Minor", "Previous", "Raw", "Soft", "Solid",
	"Weird", "Amazing", "Annual", "Busy", "Dead", "False", "Round", "Sharp",
	"Thick", "Wise", "Equivalent", "Initial", "Narrow", "Nearby", "Proud",
	"Spiritual", "Wild", "Adult", "Apart", "Brief", "Crazy", "Prior", "Rough",
	"Sad", "Sick", "Strange", "External", "Illegal", "Loud", "Mobile", "Nasty",
	"Ordinary", "Royal", "Senior", "Super", "Tight", "Upper", "Yellow",
	"Dependent", "Funny", "Gross", "Ill", "Spare", "Sweet", "Upstairs",
	"Usual", "Brave", "Calm", "Dirty", "Downtown", "Grand", "Honest", "Loose",
	"Male", "Quiet", "Brilliant", "Dear", "Drunk", "Empty", "Female",
	"Inevitable", "Neat", "Ok", "Representative", "Silly", "Slight", "Smart",
	"Stupid", "Temporary", "Weekly", "That", "This", "What", "Which", "Time",
	"These", "Work", "No", "Only", "Then", "First", "Money", "Over",
	"Business", "His", "Game", "Think", "After", "Life", "Day", "Home",
	"Economy", "Away", "Either", "Fat", "Key", "Training", "Top", "Level",
	"Far", "Fun", "House", "Kind", "Future", "Action", "Live", "Period",
	"Subject", "Mean", "Stock", "Chance", "Beginning", "Upset", "Chicken",
	"Head", "Material", "Salt", "Car", "Appropriate", "Inside", "Outside",
	"Standard", "Medium", "Choice", "North", "Square", "Born", "Capital",
	"Shot", "Front", "Living", "Plastic", "Express", "Feeling", "Otherwise",
	"Plus", "Savings", "Animal", "Budget", "Minute", "Character", "Maximum",
	"Novel", "Plenty", "Select", "Background", "Forward", "Glass", "Joint",
	"Master", "Red", "Vegetable", "Ideal", "Kitchen", "Mother", "Party",
	"Relative", "Signal", "Street", "Connect", "Minimum", "Sea", "South",
	"Status", "Daughter", "Hour", "Trick", "Afternoon", "Gold", "Mission",
	"Agent", "Corner", "East", "Neither", "Parking", "Routine", "Swimming",
	"Winter", "Airline", "Designer", "Dress", "Emergency", "Evening",
	"Extension", "Holiday", "Horror", "Mountain", "Patient", "Proof", "West",
	"Wine", "Expert", "Native", "Opening", "Silver", "Waste", "Plane",
	"Leather", "Purple", "Specialist", "Bitter", "Incident", "Motor",
	"Pretend", "Prize", "Resident",
	NULL
}; //>>>

int nounsc = 0;
static const char* nouns[] = { //<<<
	"People", "History", "Way", "Art", "World", "Information", "Map", "Two",
	"Family", "Government", "Health", "System", "Computer", "Meat", "Year",
	"Thanks", "Music", "Person", "Reading", "Method", "Data", "Food",
	"Understanding", "Theory", "Law", "Bird", "Literature", "Problem",
	"Software", "Control", "Knowledge", "Power", "Ability", "Economics",
	"Love", "Internet", "Television", "Science", "Library", "Nature", "Fact",
	"Product", "Idea", "Temperature", "Investment", "Area", "Society",
	"Activity", "Story", "Industry", "Media", "Thing", "Oven", "Community",
	"Definition", "Safety", "Quality", "Development", "Language", "Management",
	"Player", "Variety", "Video", "Week", "Security", "Country", "Exam",
	"Movie", "Organization", "Equipment", "Physics", "Analysis", "Policy",
	"Series", "Thought", "Basis", "Boyfriend", "Direction", "Strategy",
	"Technology", "Army", "Camera", "Freedom", "Paper", "Environment",
	"Instance", "Month", "Truth", "Marketing", "University", "Writing",
	"Article", "Department", "Difference", "Goal", "News", "Audience",
	"Fishing", "Growth", "Income", "Marriage", "User", "Combination",
	"Failure", "Meaning", "Medicine", "Philosophy", "Teacher", "Communication",
	"Night", "Chemistry", "Disease", "Disk", "Energy", "Nation", "Road",
	"Role", "Soup", "Advertising", "Location", "Success", "Addition",
	"Apartment", "Education", "Math", "Moment", "Painting", "Politics",
	"Attention", "Decision", "Event", "Property", "Shopping", "Student",
	"Wood", "Competition", "Distribution", "Entertainment", "Office",
	"Population", "President", "Unit", "Category", "Cigarette", "Context",
	"Introduction", "Opportunity", "Performance", "Driver", "Flight", "Length",
	"Magazine", "Newspaper", "Relationship", "Teaching", "Cell", "Dealer",
	"Finding", "Lake", "Member", "Message", "Phone", "Scene", "Appearance",
	"Association", "Concept", "Customer", "Death", "Discussion", "Housing",
	"Inflation", "Insurance", "Mood", "Woman", "Advice", "Blood", "Effort",
	"Expression", "Importance", "Opinion", "Payment", "Reality",
	"Responsibility", "Situation", "Skill", "Statement", "Wealth",
	"Application", "City", "County", "Depth", "Estate", "Foundation",
	"Grandmother", "Heart", "Perspective", "Photo", "Recipe", "Studio",
	"Topic", "Collection", "Depression", "Imagination", "Passion",
	"Percentage", "Resource", "Setting", "Ad", "Agency", "College",
	"Connection", "Criticism", "Debt", "Description", "Memory", "Patience",
	"Secretary", "Solution", "Administration", "Aspect", "Attitude",
	"Director", "Personality", "Psychology", "Recommendation", "Response",
	"Selection", "Storage", "Version", "Alcohol", "Argument", "Complaint",
	"Contract", "Emphasis", "Highway", "Loss", "Membership", "Possession",
	"Preparation", "Steak", "Union", "Agreement", "Currency",
	"Employment", "Engineering", "Entry", "Interaction", "Mixture",
	"Preference", "Region", "Republic", "Tradition", "Virus", "Actor",
	"Classroom", "Delivery", "Device", "Difficulty", "Drama", "Election",
	"Engine", "Football", "Guidance", "Hotel", "Owner", "Priority",
	"Protection", "Suggestion", "Tension", "Variation", "Anxiety",
	"Atmosphere", "Awareness", "Bath", "Bread", "Candidate", "Climate",
	"Comparison", "Confusion", "Construction", "Elevator", "Emotion",
	"Employee", "Employer", "Guest", "Height", "Leadership", "Mall", "Manager",
	"Operation", "Recording", "Sample", "Transportation", "Charity", "Cousin",
	"Disaster", "Editor", "Efficiency", "Excitement", "Extent", "Feedback",
	"Guitar", "Homework", "Leader", "Mom", "Outcome", "Permission",
	"Presentation", "Promotion", "Reflection", "Refrigerator", "Resolution",
	"Revenue", "Session", "Singer", "Tennis", "Basket", "Bonus", "Cabinet",
	"Church", "Clothes", "Coffee", "Dinner", "Drawing", "Hair",
	"Hearing", "Initiative", "Judgment", "Lab", "Measurement", "Mode", "Mud",
	"Orange", "Poetry", "Police", "Possibility", "Procedure", "Queen", "Ratio",
	"Relation", "Restaurant", "Satisfaction", "Sector", "Signature",
	"Significance", "Song", "Tooth", "Town", "Vehicle", "Volume", "Wife",
	"Accident", "Airport", "Appointment", "Arrival", "Assumption", "Baseball",
	"Chapter", "Committee", "Conversation", "Database", "Enthusiasm", "Error",
	"Explanation", "Farmer", "Gate", "Girl", "Hall", "Historian", "Hospital",
	"Injury", "Instruction", "Maintenance", "Manufacturer", "Meal",
	"Perception", "Pie", "Poem", "Presence", "Proposal", "Reception",
	"Replacement", "Revolution", "River", "Son", "Speech", "Tea", "Village",
	"Warning", "Winner", "Worker", "Writer", "Assistance", "Breath", "Buyer",
	"Chest", "Chocolate", "Conclusion", "Contribution", "Cookie", "Courage",
	"Dad", "Desk", "Drawer", "Establishment", "Examination", "Garbage",
	"Grocery", "Honey", "Impression", "Improvement", "Independence", "Insect",
	"Inspection", "Inspector", "King", "Ladder", "Menu", "Penalty", "Piano",
	"Potato", "Profession", "Professor", "Quantity", "Reaction", "Requirement",
	"Salad", "Sister", "Supermarket", "Tongue", "Weakness", "Wedding",
	"Affair", "Ambition", "Analyst", "Apple", "Assignment", "Assistant",
	"Bathroom", "Bedroom", "Beer", "Birthday", "Celebration", "Championship",
	"Cheek", "Client", "Consequence", "Departure", "Diamond", "Dirt", "Ear",
	"Fortune", "Friendship", "Funeral", "Gene", "Girlfriend", "Hat",
	"Indication", "Intention", "Lady", "Midnight", "Negotiation", "Obligation",
	"Passenger", "Pizza", "Platform", "Poet", "Pollution", "Recognition",
	"Reputation", "Shirt", "Sir", "Speaker", "Stranger", "Surgery", "Sympathy",
	"Tale", "Throat", "Trainer", "Uncle", "Youth", "Time", "Work", "Film",
	"Water", "Money", "Example", "While", "Business", "Study", "Game", "Life",
	"Form", "Air", "Day", "Place", "Number", "Part", "Field", "Fish", "Back",
	"Process", "Heat", "Hand", "Experience", "Job", "Book", "End", "Point",
	"Type", "Home", "Economy", "Value", "Body", "Market", "Guide", "Interest",
	"State", "Radio", "Course", "Company", "Price", "Size", "Card", "List",
	"Mind", "Trade", "Line", "Care", "Group", "Risk", "Word", "Fat", "Force",
	"Key", "Light", "Training", "Name", "School", "Top", "Amount", "Level",
	"Order", "Practice", "Research", "Sense", "Service", "Piece", "Web",
	"Boss", "Sport", "Fun", "House", "Page", "Term", "Test", "Answer", "Sound",
	"Focus", "Matter", "Kind", "Soil", "Board", "Oil", "Picture", "Access",
	"Garden", "Range", "Rate", "Reason", "Future", "Site", "Demand",
	"Exercise", "Image", "Case", "Cause", "Coast", "Action", "Age", "Bad",
	"Boat", "Record", "Result", "Section", "Building", "Mouse", "Cash",
	"Class", "Nothing", "Period", "Plan", "Store", "Tax", "Side", "Subject",
	"Space", "Rule", "Stock", "Weather", "Chance", "Figure", "Man", "Model",
	"Source", "Beginning", "Earth", "Program", "Chicken", "Design", "Feature",
	"Head", "Material", "Purpose", "Question", "Rock", "Salt", "Act", "Birth",
	"Car", "Dog", "Object", "Scale", "Sun", "Note", "Profit", "Rent", "Speed",
	"Style", "War", "Bank", "Craft", "Half", "Inside", "Outside", "Standard",
	"Bus", "Exchange", "Eye", "Fire", "Position", "Pressure", "Stress",
	"Advantage", "Benefit", "Box", "Frame", "Issue", "Step", "Cycle", "Face",
	"Item", "Metal", "Paint", "Review", "Room", "Screen", "Structure", "View",
	"Account", "Ball", "Discipline", "Medium", "Share", "Balance", "Bit",
	"Black", "Bottom", "Choice", "Gift", "Impact", "Machine", "Shape", "Tool",
	"Wind", "Address", "Average", "Career", "Culture", "Morning", "Pot",
	"Sign", "Table", "Task", "Condition", "Contact", "Credit", "Egg", "Hope",
	"Ice", "Network", "North", "Square", "Attempt", "Date", "Effect", "Link",
	"Post", "Star", "Voice", "Capital", "Challenge", "Friend", "Self", "Shot",
	"Brush", "Couple", "Debate", "Exit", "Front", "Function", "Lack", "Living",
	"Plant", "Plastic", "Spot", "Summer", "Taste", "Theme", "Track", "Wing",
	"Brain", "Button", "Click", "Desire", "Foot", "Gas", "Influence", "Notice",
	"Rain", "Wall", "Base", "Damage", "Distance", "Feeling", "Pair", "Savings",
	"Staff", "Sugar", "Target", "Text", "Animal", "Author", "Budget",
	"Discount", "File", "Ground", "Lesson", "Minute", "Officer", "Phase",
	"Reference", "Register", "Sky", "Stage", "Stick", "Title", "Trouble",
	"Bowl", "Bridge", "Campaign", "Character", "Club", "Edge", "Evidence",
	"Fan", "Letter", "Lock", "Maximum", "Novel", "Option", "Pack", "Park",
	"Plenty", "Quarter", "Skin", "Sort", "Weight", "Baby", "Background",
	"Carry", "Dish", "Factor", "Fruit", "Glass", "Joint", "Master", "Muscle",
	"Red", "Strength", "Traffic", "Trip", "Vegetable", "Appeal", "Chart",
	"Gear", "Ideal", "Kitchen", "Land", "Log", "Mother", "Net", "Party",
	"Principle", "Relative", "Sale", "Season", "Signal", "Spirit", "Street",
	"Tree", "Wave", "Belt", "Bench", "Commission", "Copy", "Drop", "Minimum",
	"Path", "Progress", "Project", "Sea", "South", "Status", "Stuff", "Ticket",
	"Tour", "Angle", "Blue", "Breakfast", "Confidence", "Daughter", "Degree",
	"Doctor", "Dot", "Dream", "Duty", "Essay", "Father", "Fee", "Finance",
	"Hour", "Juice", "Limit", "Luck", "Milk", "Mouth", "Peace", "Pipe", "Seat",
	"Stable", "Storm", "Substance", "Team", "Trick", "Afternoon", "Bat",
	"Beach", "Blank", "Catch", "Chain", "Consideration", "Cream", "Crew",
	"Detail", "Gold", "Interview", "Mark", "Match", "Mission", "Pain",
	"Pleasure", "Score", "Screw", "Shop", "Shower", "Suit", "Tone",
	"Window", "Agent", "Band", "Block", "Bone", "Calendar", "Cap", "Coat",
	"Contest", "Corner", "Court", "Cup", "District", "Door", "East", "Finger",
	"Garage", "Guarantee", "Hole", "Hook", "Implement", "Layer", "Lecture",
	"Lie", "Manner", "Meeting", "Nose", "Parking", "Partner", "Profile",
	"Respect", "Rice", "Routine", "Schedule", "Swimming", "Telephone", "Tip",
	"Winter", "Airline", "Bag", "Battle", "Bed", "Bill", "Bother", "Cake",
	"Code", "Curve", "Designer", "Dimension", "Dress", "Ease", "Emergency",
	"Evening", "Extension", "Farm", "Fight", "Gap", "Grade", "Holiday",
	"Horror", "Horse", "Host", "Husband", "Loan", "Mistake", "Mountain",
	"Nail", "Noise", "Occasion", "Package", "Patient", "Pause", "Phrase",
	"Proof", "Race", "Relief", "Sand", "Sentence", "Shoulder", "Smoke",
	"Stomach", "String", "Tourist", "Towel", "Vacation", "West", "Wheel",
	"Wine", "Arm", "Aside", "Associate", "Bet", "Blow", "Border", "Branch",
	"Breast", "Brother", "Buddy", "Bunch", "Chip", "Coach", "Cross",
	"Document", "Draft", "Dust", "Expert", "Floor", "God", "Golf", "Habit",
	"Iron", "Judge", "Knife", "Landscape", "League", "Mail", "Mess", "Native",
	"Opening", "Parent", "Pattern", "Pin", "Pool", "Pound", "Request",
	"Salary", "Shame", "Shelter", "Shoe", "Silver", "Tackle", "Tank", "Trust",
	"Assist", "Bake", "Bar", "Bell", "Bike", "Blame", "Boy", "Brick", "Chair",
	"Closet", "Clue", "Collar", "Comment", "Conference", "Devil", "Diet",
	"Fear", "Fuel", "Glove", "Jacket", "Lunch", "Monitor", "Mortgage", "Nurse",
	"Pace", "Panic", "Peak", "Plane", "Reward", "Row", "Sandwich", "Shock",
	"Spite", "Spray", "Surprise", "Till", "Transition", "Weekend", "Welcome",
	"Yard", "Alarm", "Bend", "Bicycle", "Bite", "Blind", "Bottle", "Cable",
	"Candle", "Clerk", "Cloud", "Concert", "Counter", "Flower", "Grandfather",
	"Harm", "Knee", "Lawyer", "Leather", "Load", "Mirror", "Neck", "Pension",
	"Plate", "Purple", "Ruin", "Ship", "Skirt", "Slice", "Snow", "Specialist",
	"Stroke", "Switch", "Trash", "Tune", "Zone", "Anger", "Award", "Bid",
	"Bitter", "Boot", "Bug", "Camp", "Candy", "Carpet", "Cat", "Champion",
	"Channel", "Clock", "Comfort", "Cow", "Crack", "Engineer", "Entrance",
	"Fault", "Grass", "Guy", "Hell", "Highlight", "Incident", "Island", "Joke",
	"Jury", "Leg", "Lip", "Mate", "Motor", "Nerve", "Passage", "Pen", "Pride",
	"Priest", "Prize", "Promise", "Resident", "Resort", "Ring", "Roof", "Rope",
	"Sail", "Scheme", "Script", "Sock", "Station", "Toe", "Tower", "Truck",
	"Witness", "A", "You", "It", "Can", "Will", "If", "One", "Many", "Most",
	"Other", "Use", "Make", "Good", "Look", "Help", "Go", "Great", "Being",
	"Few", "Might", "Still", "Public", "Read", "Keep", "Start", "Give",
	"Human", "Local", "General", "She", "Specific", "Long", "Play", "Feel",
	"High", "Tonight", "Put", "Common", "Set", "Change", "Simple", "Past",
	"Big", "Possible", "Particular", "Today", "Major", "Personal", "Current",
	"National", "Cut", "Natural", "Physical", "Show", "Try", "Check", "Second",
	"Call", "Move", "Pay", "Let", "Increase", "Single", "Individual", "Turn",
	"Ask", "Buy", "Guard", "Hold", "Main", "Offer", "Potential",
	"Professional", "International", "Travel", "Cook", "Alternative",
	"Following", "Special", "Working", "Whole", "Dance", "Excuse", "Cold",
	"Commercial", "Low", "Purchase", "Deal", "Primary", "Worth", "Fall",
	"Necessary", "Positive", "Produce", "Search", "Present", "Spend", "Talk",
	"Creative", "Tell", "Cost", "Drive", "Green", "Support", "Glad", "Remove",
	"Return", "Run", "Complex", "Due", "Effective", "Middle", "Regular",
	"Reserve", "Independent", "Leave", "Original", "Reach", "Rest", "Serve",
	"Watch", "Beautiful", "Charge", "Active", "Break", "Negative", "Safe",
	"Stay", "Visit", "Visual", "Affect", "Cover", "Report", "Rise", "Walk",
	"White", "Beyond", "Junior", "Pick", "Unique", "Anything", "Classic",
	"Final", "Lift", "Mix", "Private", "Stop", "Teach", "Western", "Concern",
	"Familiar", "Fly", "Official", "Broad", "Comfortable", "Gain", "Maybe",
	"Rich", "Save", "Stand", "Young", "Fail", "Heavy", "Hello", "Lead",
	"Listen", "Valuable", "Worry", "Handle", "Leading", "Meet", "Release",
	"Sell", "Finish", "Normal", "Press", "Ride", "Secret", "Spread", "Spring",
	"Tough", "Wait", "Brown", "Deep", "Display", "Flow", "Hit", "Objective",
	"Shoot", "Touch", "Cancel", "Chemical", "Cry", "Dump", "Extreme", "Push",
	"Conflict", "Eat", "Fill", "Formal", "Jump", "Kick", "Opposite", "Pass",
	"Pitch", "Remote", "Total", "Treat", "Vast", "Abuse", "Beat", "Burn",
	"Deposit", "Print", "Raise", "Sleep", "Somewhere", "Advance", "Anywhere",
	"Consist", "Dark", "Double", "Draw", "Equal", "Fix", "Hire", "Internal",
	"Join", "Kill", "Sensitive", "Tap", "Win", "Attack", "Claim", "Constant",
	"Drag", "Drink", "Guess", "Minor", "Pull", "Raw", "Soft", "Solid", "Wear",
	"Weird", "Wonder", "Annual", "Count", "Dead", "Doubt", "Feed", "Forever",
	"Impress", "Nobody", "Repeat", "Round", "Sing", "Slide", "Strip",
	"Whereas", "Wish", "Combine", "Command", "Dig", "Divide", "Equivalent",
	"Hang", "Hunt", "Initial", "March", "Mention", "Smell", "Spiritual",
	"Survey", "Tie", "Adult", "Brief", "Crazy", "Escape", "Gather", "Hate",
	"Prior", "Repair", "Rough", "Sad", "Scratch", "Sick", "Strike", "Employ",
	"External", "Hurt", "Illegal", "Laugh", "Lay", "Mobile", "Nasty",
	"Ordinary", "Respond", "Royal", "Senior", "Split", "Strain", "Struggle",
	"Swim", "Train", "Upper", "Wash", "Yellow", "Convert", "Crash",
	"Dependent", "Fold", "Funny", "Grab", "Hide", "Miss", "Permit", "Quote",
	"Recover", "Resolve", "Roll", "Sink", "Slip", "Spare", "Suspect", "Sweet",
	"Swing", "Twist", "Upstairs", "Usual", "Abroad", "Brave", "Calm",
	"Concentrate", "Estimate", "Grand", "Male", "Mine", "Prompt", "Quiet",
	"Refuse", "Regret", "Reveal", "Rush", "Shake", "Shift", "Shine", "Steal",
	"Suck", "Surround", "Anybody", "Bear", "Brilliant", "Dare", "Dear",
	"Delay", "Drunk", "Female", "Hurry", "Inevitable", "Invite", "Kiss",
	"Neat", "Pop", "Punch", "Quit", "Reply", "Representative", "Resist", "Rip",
	"Rub", "Silly", "Smile", "Spell", "Stretch", "Stupid", "Tear", "Temporary",
	"Tomorrow", "Wake", "Wrap", "Yesterday",
	NULL
}; //>>>
#define	MAXLEN 41

#define FG_PREFIX	"\x1B[38;2;"
#define BG_PREFIX	"\x1B[48;2;"
#define NORM		"\x1B[0m"
#define FG(r,g,b)	FG_PREFIX #r ";" #g ";" #b "m"
#define BG(r,g,b)	BG_PREFIX #r ";" #g ";" #b "m"

#define MAX_COL_LEN	sizeof(FG_PREFIX)-1 +(3+1)*4/* r,g,b */  + sizeof(NORM)-1


static atomic_uint_fast64_t log_delta_last_nsec = 0;

static inline double log_delta_usec(void) { //<<<
	struct timespec ts;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts);
	const uint64_t nsec = ts.tv_sec*1000000000 + ts.tv_nsec;
	const uint64_t last = atomic_exchange(&log_delta_last_nsec, nsec);
	return (nsec - last)/1e3;
}

//>>>
static inline double proctime(void) { //<<<
	struct timespec ts;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts);
	return ts.tv_sec + ts.tv_nsec/1e9;
}
//>>>
static inline double threadtime(void) { //<<<
	struct timespec ts;
	clock_gettime(CLOCK_THREAD_CPUTIME_ID, &ts);
	return ts.tv_sec + ts.tv_nsec/1e9;
}
//>>>


static int	maxlen_adjective = 0;
static int	maxlen_noun = 0;
#define STATICBUFS	10
thread_local char	out[STATICBUFS][MAXLEN+MAX_COL_LEN];
thread_local int	outslot_i;


static inline uint64_t hash64shift(uint64_t key) // Adapted from https://gist.github.com/badboy/6267743 <<<
{
	key = (~key) + (key << 21); // key = (key << 21) - key - 1;
	key = key ^ (key >> 24);
	key = (key + (key << 3)) + (key << 8); // key * 265
	key = key ^ (key >> 14);
	key = (key + (key << 2)) + (key << 4); // key * 21
	key = key ^ (key >> 28);
	key = key + (key << 31);
	return key;
}

//>>>
static inline void shuffle(uint64_t* n) //<<<
{
	*n = hash64shift(*n);
}

//>>>
static void init() //<<<
{
	for (adjectivesc=0; adjectives[adjectivesc]; adjectivesc++) {
		const int len = strlen(adjectives[adjectivesc]);
		if (len > maxlen_adjective) maxlen_adjective = len;
	}

	for (nounsc=0; nouns[nounsc]; nounsc++) {
		const int len = strlen(nouns[nounsc]);
		if (len > maxlen_noun) maxlen_noun = len;
	}

	if (maxlen_adjective + maxlen_noun + 1 > MAXLEN)
		fprintf(stderr, "clogs: maxlen_adjective + maxlen_noun + 1 > MAXLEN\n");
}

//>>>
const char* randwords(intptr_t seedraw) //<<<
{
	const uint64_t	rand = hash64shift(seedraw);
	const int		adj  =  rand      % adjectivesc;
	const int		noun = (rand>>16) % nounsc;

	const int			outslot = outslot_i++ % STATICBUFS;
	char*restrict		p = out[outslot];
	const char*restrict	s;
	s = adjectives[adj]; while (*s) *p++ = *s++;
	s = nouns[noun];     while (*s) *p++ = *s++;
	memcpy(p, NORM, sizeof(NORM)-1); p += sizeof(NORM)-1;
	*p = '\0';
	
	return out[outslot];
}

//>>>
static once_flag	autoinit = ONCE_FLAG_INIT;
const char* clogs_name(const void *const thing) //<<<
{
	call_once(&autoinit, init);
	return thing ? randwords((intptr_t)thing) : "NULL";
}

//>>>
static const char* byte_decimals[0x100] = { //<<<
	"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
	"11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
	"21", "22", "23", "24", "25", "26", "27", "28", "29", "30",
	"31", "32", "33", "34", "35", "36", "37", "38", "39", "40",
	"41", "42", "43", "44", "45", "46", "47", "48", "49", "50",
	"51", "52", "53", "54", "55", "56", "57", "58", "59", "60",
	"61", "62", "63", "64", "65", "66", "67", "68", "69", "70",
	"71", "72", "73", "74", "75", "76", "77", "78", "79", "80",
	"81", "82", "83", "84", "85", "86", "87", "88", "89", "90",
	"91", "92", "93", "94", "95", "96", "97", "98", "99", "100",
	"101", "102", "103", "104", "105", "106", "107", "108", "109", "110",
	"111", "112", "113", "114", "115", "116", "117", "118", "119", "120",
	"121", "122", "123", "124", "125", "126", "127", "128", "129", "130",
	"131", "132", "133", "134", "135", "136", "137", "138", "139", "140",
	"141", "142", "143", "144", "145", "146", "147", "148", "149", "150",
	"151", "152", "153", "154", "155", "156", "157", "158", "159", "160",
	"161", "162", "163", "164", "165", "166", "167", "168", "169", "170",
	"171", "172", "173", "174", "175", "176", "177", "178", "179", "180",
	"181", "182", "183", "184", "185", "186", "187", "188", "189", "190",
	"191", "192", "193", "194", "195", "196", "197", "198", "199", "200",
	"201", "202", "203", "204", "205", "206", "207", "208", "209", "210",
	"211", "212", "213", "214", "215", "216", "217", "218", "219", "220",
	"221", "222", "223", "224", "225", "226", "227", "228", "229", "230",
	"231", "232", "233", "234", "235", "236", "237", "238", "239", "240",
	"241", "242", "243", "244", "245", "246", "247", "248", "249", "250",
	"251", "252", "253", "254", "255"
};

//>>>
static inline void pick_near(char*restrict* out, uint64_t rand, uint8_t r, uint8_t g, uint8_t b) //<<<
{
	int r2 = r + ( rand        & 0x7F) - 16;
	int g2 = g + ((rand >>  8) & 0x7F) - 16;
	int b2 = b + ((rand >> 16) & 0x7F) - 16;

	if      (r2 < 0x00) r2 = 0x00;
	else if (r2 > 0xFF) r2 = 0xFF;

	if      (g2 < 0x00) g2 = 0x00;
	else if (g2 > 0xFF) g2 = 0xFF;

	if      (b2 < 0x00) b2 = 0x00;
	else if (b2 > 0xFF) b2 = 0xFF;

	char*restrict		p = *out;
	const char*restrict	s;
	s = byte_decimals[r2]; while (*s) *p++ = *s++; *p++ = ';';
	s = byte_decimals[g2]; while (*s) *p++ = *s++; *p++ = ';';
	s = byte_decimals[b2]; while (*s) *p++ = *s++; *p++ = 'm';

	*out = p;
}

//>>>
const char* clogs_cname(const void*const thing, const uint8_t r, const uint8_t g, const uint8_t b) //<<<
{
	call_once(&autoinit, init);

	const uint64_t	rand = hash64shift((intptr_t)thing);
	const int		adj  =  rand      % adjectivesc;
	const int		noun = (rand>>16) % nounsc;

	const int			outslot = outslot_i++ % STATICBUFS;
	char*restrict		p = out[outslot];
	const char*restrict	s;

	memcpy(p, FG_PREFIX, sizeof(FG_PREFIX)-1); p += sizeof(FG_PREFIX)-1;
	pick_near(&p, rand, r, g, b);
	s = adjectives[adj]; while (*s) *p++ = *s++;
	s = nouns[noun];     while (*s) *p++ = *s++;
	memcpy(p, NORM, sizeof(NORM)-1); p += sizeof(NORM)-1;
	*p = '\0';
	
	return out[outslot];
}

//>>>
const char* clogs_thread_name() //<<<
{
	static tss_t	key;
	char*			name = tss_get(key);
	if (name == NULL && thrd_success == tss_create(&key, free)) {
		name = strdup(clogs_cname((void*)thrd_current(), 0xFF, 0x60, 0x80));
		tss_set(key, name);
	}
	return name;
}

//>>>
const char* clogs_cstr(const char*const str, const uint8_t r, const uint8_t g, const uint8_t b) //<<<
{
	const uint64_t		rand = hash64shift((intptr_t)str);
	const int			outslot = outslot_i++ % STATICBUFS;
	char*restrict		p = out[outslot];

	memcpy(p, FG_PREFIX, sizeof(FG_PREFIX)-1); p += sizeof(FG_PREFIX)-1;
	pick_near(&p, rand, r, g, b);
	const char*restrict	s = str; while (*s) *p++ = *s++;
	memcpy(p, NORM, sizeof(NORM)-1); p += sizeof(NORM)-1;
	*p = '\0';
	
	return out[outslot];
}

//>>>

// vim: ts=4 shiftwidth=4 foldmethod=marker foldmarker=<<<,>>>
